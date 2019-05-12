#include "ChessBoard.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "Pawn.h"
#include "errors.h"
#include<string>
#include<iostream>

using namespace std;


ChessBoard::ChessBoard() {
  first_game = true;
  resetBoard();
}


void ChessBoard::resetBoard() {

  cout << "A new chess game is started!" << endl;

  if (!first_game)
    clean_board();

  first_game = false;
  game_ended = false;
  error_code = NO_ERROR;
  playing_colour = White;

  board.insert({"A1", new Rook (White)});
  board.insert({"B1", new Knight (White)});
  board.insert({"C1", new Bishop (White)});
  board.insert({"D1", new Queen (White)});
  board.insert({"E1", new King (White)});
  board.insert({"F1", new Bishop (White)});
  board.insert({"G1", new Knight (White)});
  board.insert({"H1", new Rook (White)});

  string key;
  for (char file = MIN_FILE; file <= MAX_FILE; file++) {
    key = string(1, file) + to_string(MIN_RANK + 1);
    board.insert({key, new Pawn (White)});
  }

  board.insert({"A8", new Rook (Black)});
  board.insert({"B8", new Knight (Black)});
  board.insert({"C8", new Bishop (Black)});
  board.insert({"D8", new Queen (Black)});
  board.insert({"E8", new King (Black)});
  board.insert({"F8", new Bishop (Black)});
  board.insert({"G8", new Knight (Black)});
  board.insert({"H8", new Rook (Black)});

  for (char file = MIN_FILE; file <= MAX_FILE; file++) {
    key = string(1, file) + to_string(MAX_RANK - 1);
    board.insert({key, new Pawn (Black)});
  }
}

ChessBoard::~ChessBoard() {
  clean_board();
}


void ChessBoard::clean_board() {
  for (Board::iterator it = board.begin(); it != board.end();) {
    if (board.find(it->first) != board.end()) {
      delete it->second;
      it = board.erase(it); 
    }
    else {
      ++it;
    }
  }
}


void ChessBoard::switch_colour() {
  ((playing_colour == White) ? playing_colour = Black : playing_colour = White) ;
}


bool ChessBoard::is_valid_move(string source_square, string dest_square) {

  if (game_ended) {
    error_code = GAME_ENDED;
    return false;
  }

  // Checking for length of source and destination square being 2
  if (source_square.size() != 2) {
    error_code = INCORRECT_SOURCE_SQUARE;
    return false;
  }
  else if (dest_square.size() != 2) {
    error_code = INCORRECT_DEST_SQUARE;
    return false;
  }

  char source_file = source_square.at(0);
  char source_rank = source_square.at(1);
  char dest_file = dest_square.at(0);
  char dest_rank = dest_square.at(1);

  // Checking for provided source and destination squares
  if ((source_file < MIN_FILE) || (source_file > MAX_FILE)) {
    error_code = INCORRECT_SOURCE_SQUARE;
    return false;
  }
  else if ((source_rank < static_cast<char>(MIN_RANK + '0'))
	   || (source_rank > static_cast<char>(MAX_RANK + '0'))) {
    error_code = INCORRECT_SOURCE_SQUARE;
    return false;
  }
  else if ((dest_file < MIN_FILE) || (dest_file > MAX_FILE)) {
    error_code = INCORRECT_DEST_SQUARE;
    return false;
  }
  else if ((dest_rank < static_cast<char>(MIN_RANK + '0')
	    || (dest_rank > static_cast<char>(MAX_RANK + '0')))) {
    error_code = INCORRECT_DEST_SQUARE;
    return false;
  }
  else if (source_square == dest_square) {
    error_code = SAME_SOURCE_DEST_SQUARES;
    return false;
  }

  // Checking if a piece actually exists on the source square
  if (board.count(source_square) == 0) {
    error_code = NO_SOURCE_PIECE;
    return false;
  }

  // Checking if player's turn matches with the colour of piece moved,
  // or if a player is trying to capture one of its own pieces
  if ((board.count(source_square) != 0) && (playing_colour != board[source_square]->get_colour())) {
    error_code = OPPONENT_PIECE;
    return false;
  }
  else if ((board.count(dest_square) != 0) && (playing_colour == board[dest_square]->get_colour())) {
    error_code = FRIENDLY_PIECE;
    return false;
  }

  // Checking if the piece selected can make the specified move
  if (!board[source_square]->piece_valid_move(source_square, dest_square, board, error_code)) {
    return false;
  }

  return true;
}


void ChessBoard::print_error(string source_square, string dest_square) {
  switch (error_code) {
  case NO_ERROR:
    cerr << "There are no errors in the program!" << endl;
    break;
  case GAME_ENDED:
    cerr << "The game has ended. No more moves allowed!" << endl;
    break;
  case INCORRECT_SOURCE_SQUARE:
    cerr << "The source square " << source_square << " is incorrect!" << endl;
    break;
  case INCORRECT_DEST_SQUARE:
    cerr << "The destination square " << dest_square << " is incorrect!" << endl;
    break;
  case SAME_SOURCE_DEST_SQUARES:
    cerr << "The provided destination square is the same as the source square. The ";
    cerr << (playing_colour == 1 ? "WHITE" : "BLACK") << " player needs to move a piece!" << endl;
    break;
  case NO_SOURCE_PIECE:
    cerr << "There is no piece at position " << source_square << "!" << endl;
    break;
  case OPPONENT_PIECE:
    cerr << "It is not " << (playing_colour == White ? "Black" : "White") << "'s turn to move!" << endl;
    break;
  case FRIENDLY_PIECE:
    cerr << "The " << (playing_colour == White ? "WHITE" : "BLACK") << " player is trying to capture one ";
    cerr << "of his own pieces! Come on, there are better ways to lose a game!" << endl;
    break;
  case INVALID_PAWN_MOVE:
    cerr << (playing_colour == White ? "White" : "Black") << "'s " << board[source_square]->get_name_piece();
    cerr << " cannot move to " << dest_square << "!" << endl;
    break;
  case INVALID_ROOK_MOVE:
    cerr << (playing_colour == White ? "White" : "Black") << "'s " << board[source_square]->get_name_piece();
    cerr << " cannot move to " << dest_square << "!" << endl;
    break;
  case INVALID_KNIGHT_MOVE:
    cerr << (playing_colour == White ? "White" : "Black") << "'s " << board[source_square]->get_name_piece();
    cerr << " cannot move to " << dest_square << "!" << endl;
    break;
  case INVALID_BISHOP_MOVE:
    cerr << (playing_colour == White ? "White" : "Black") << "'s " << board[source_square]->get_name_piece();
    cerr << " cannot move to " << dest_square << "!" << endl;
    break;
  case INVALID_QUEEN_MOVE:
    cerr << (playing_colour == White ? "White" : "Black") << "'s " << board[source_square]->get_name_piece();
    cerr << " cannot move to " << dest_square << "!" << endl;
    break;
  case INVALID_KING_MOVE:
    cerr << (playing_colour == White ? "White" : "Black") << "'s " << board[source_square]->get_name_piece();
    cerr << " cannot move to " << dest_square << "!" << endl;
    break;
  case SELF_IN_CHECK:
    cerr << "You cannot make this move because you put yourself in check!" << endl;
    break;
  }
}


bool ChessBoard::is_in_check() {
  string king_pos;
  for (Board::iterator it = board.begin(); it != board.end(); it++)
    if (playing_colour == it->second->get_colour())
      if (it->second->get_name_piece() == "King")
	king_pos = it->first;

  for (Board::iterator it = board.begin(); it != board.end(); it++) {
    if (playing_colour != it->second->get_colour())
      if (it->second->piece_valid_move(it->first, king_pos, board, error_code)) {
	return true;
      }
  }

  return false;
}


bool ChessBoard::cannot_makemove() {
  string position;
  Piece* tmp_ptr;

  for (char file = MIN_FILE; file <= MAX_FILE; file++)
    for (int rank = MIN_RANK; rank <= MAX_RANK; rank++) {
      string source_square = string(1, file) + to_string(rank);
      if ((board.count(source_square) != 0) && (playing_colour == board[source_square]->get_colour()))
	for (char i = MIN_FILE; i <= MAX_FILE; i++)
	  for (int j = MIN_RANK; j <= MAX_RANK; j++) {
	    position = string(1, i) + to_string(j);
	    if (is_valid_move(source_square, position)) {
	      bool is_piece = false;
	      if (board.count(position) != 0) {
		tmp_ptr = board[position];
		is_piece = true;
	      }
	      board[position] = board[source_square];
	      board.erase(source_square);
	      if (is_in_check()) {
		board[source_square] = board[position];
		board.erase(position);
		if (is_piece)
		  board[position] = tmp_ptr;
	      }
	      else {
		board[source_square] = board[position];
		board.erase(position);
		if (is_piece)
		  board[position] = tmp_ptr;
		return false;
	      }
	    }
	  }
    }
  return true;
}


void ChessBoard::print_frame() { cout << "  +-----+-----+-----+-----+-----+-----+-----+-----+" << endl; }


void ChessBoard::print_row(int rank) {
  cout << (char) (static_cast<char>(MAX_RANK + '0') - rank) << " ";
  string string_file;
  string string_rank;
  string_rank = to_string(8 - rank);
  for (char i = MIN_FILE; i <= MAX_FILE; i++) {
    string_file = string(1,i);
      cout << ':';
      if (board.count(string_file + string_rank) == 0)
	cout << "     ";
      else
	cout << "  " << board[string_file + string_rank]->get_piece() << "  ";
    }
  cout << "|" << endl;
}


void ChessBoard::display_board() {
  cout << "    ";
  for (int r = MIN_RANK - 1; r < MAX_RANK; r++)
    cout << " " << (char) (MIN_FILE + r) << "    ";
  cout << endl;
  for (int r = MIN_RANK - 1; r < MAX_RANK; r++) {
    print_frame();
    print_row(r);
  }
  print_frame();
}


bool ChessBoard::is_castling(string source_square, string dest_square, Board board) {

  char source_file = source_square.at(0);
  char dest_file = dest_square.at(0);
  int file_change = dest_file - source_file;

  string king_pos;
  for (Board::iterator it = board.begin(); it != board.end(); it++)
    if (playing_colour == it->second->get_colour())
      if (it->second->get_name_piece() == "King")
	king_pos = it->first;

  if ((king_pos == source_square) && (abs(file_change) == 2))
    return true;

  return false;
}


void ChessBoard::submitMove(string source_square, string dest_square) {

  if (!is_valid_move(source_square, dest_square)) {
    print_error(source_square, dest_square);
    return;
  }

  char source_file = source_square.at(0);
  char source_rank = source_square.at(1);
  char dest_file = dest_square.at(0);
  int file_change = dest_file - source_file;

  if (is_castling(source_square, dest_square, board)) {
    string old_rook_square;
    string new_rook_square;
    if (file_change > 0) {
      board[dest_square] = board[source_square];
      board.erase(source_square);

      old_rook_square = string(1, MAX_FILE) + string(1 , source_rank);
      new_rook_square = string(1, MAX_FILE - 2) + string(1 , source_rank);

      board[new_rook_square] = board[old_rook_square];
      board.erase(old_rook_square);
    }
    if (file_change < 0) {
      board[dest_square] = board[source_square];
      board.erase(source_square);

      old_rook_square = string(1, MIN_FILE) + string(1 , source_rank);
      new_rook_square = string(1, MIN_FILE + 3) + string(1 , source_rank);

      board[new_rook_square] = board[old_rook_square];
      board.erase(old_rook_square);
    }
    
    cout << (playing_colour == White ? "White" : "Black") << "'s " << board[dest_square]->get_name_piece();
    cout << " moves from " << source_square << " to " << dest_square << " and ";
    cout << (playing_colour == White ? "White" : "Black") << "'s " << board[new_rook_square]->get_name_piece();
    cout << " moves from " << old_rook_square << " to " << new_rook_square << " performing castling" << endl;
    
    // Set the first move to false
    dynamic_cast<Rook*>(board[new_rook_square])->set_first_move(false);
    dynamic_cast<King*>(board[dest_square])->set_first_move(false);
    
    switch_colour();

    if (is_in_check()) {
      // checking for checkmate
      if (cannot_makemove()) {
	game_ended = true;
	cout << (playing_colour == White ? "White" : "Black") << " is in checkmate" << endl;
      }
      else
	cout << (playing_colour == White ? "White" : "Black") << " is in check" << endl;
    }
    else {
      // checking for stalemate
      if (cannot_makemove()) {
	game_ended = true;
	cout << "The game has now ended with a stalemate!" << endl;
      }
    }
    return ;
  }

  Piece* tmp_ptr;
  bool is_piece = false;
  if (board.count(dest_square) != 0) {
    tmp_ptr = board[dest_square];
    is_piece = true;
  }

  board[dest_square] = board[source_square];
  board.erase(source_square);

  // If putting myself in check undo a move
  if (is_in_check()) {
    board[source_square] = board[dest_square];
    board.erase(dest_square);
    if (is_piece)
      board[dest_square] = tmp_ptr;
    error_code = SELF_IN_CHECK;
    print_error(source_square, dest_square);
    return;
  }
  else {
    if (is_piece) {
      cout << (playing_colour == White ? "White" : "Black") << "'s " << board[dest_square]->get_name_piece();
      cout << " moves from " << source_square << " to " << dest_square << " taking ";
      cout << (playing_colour == White ? "Black" : "White") << "'s " << tmp_ptr->get_name_piece() << endl;
      delete tmp_ptr;
    }
    else {
      cout << (playing_colour == White ? "White" : "Black") << "'s " << board[dest_square]->get_name_piece();
      cout << " moves from " << source_square << " to " << dest_square << endl;
    }
  }

// Set the first move to false
  if (board[dest_square]->get_name_piece() == "Pawn") {
    dynamic_cast<Pawn*>(board[dest_square])->set_first_move(false);
  }

 if (board[dest_square]->get_name_piece() == "Rook") {
  dynamic_cast<Rook*>(board[dest_square])->set_first_move(false);
 }

 if (board[dest_square]->get_name_piece() == "King") {
  dynamic_cast<King*>(board[dest_square])->set_first_move(false);
 }

  switch_colour();
  
  if (is_in_check()) {
    // checking for checkmate
    if (cannot_makemove()) {
      game_ended = true;
      cout << (playing_colour == White ? "White" : "Black") << " is in checkmate" << endl;
    }
    else
      cout << (playing_colour == White ? "White" : "Black") << " is in check" << endl;
  }
  else {
    // checking for stalemate
    if (cannot_makemove()) {
      game_ended = true;
      cout << "The game has now ended with a stalemate!" << endl;
    }
  }
}
