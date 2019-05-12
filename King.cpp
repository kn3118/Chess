#include "King.h"
#include "errors.h"
#include <iostream>
#include<cstdlib>

using namespace std;

King::King(Colour col) : Piece(col) { first_move = true; }


King::~King() {}


string King::get_piece() { return (piece_colour == White ? "♔" : "♚" ); }


string King::get_name_piece() { return "King"; }


bool King::is_first_move() { return first_move; }


void King::set_first_move(bool state) { first_move = state; }


bool King::piece_valid_move(string source_square, string dest_square, Board board, int& error_code) {

  bool castling = true;
  char source_file = source_square.at(0);
  char source_rank = source_square.at(1);
  char dest_file = dest_square.at(0);
  char dest_rank = dest_square.at(1);

  int file_change = dest_file - source_file;
  int rank_change = dest_rank - source_rank;

  string right_side = string(1, MAX_FILE) + string(1, source_rank);
  string left_side = string(1, MIN_FILE) + string(1, source_rank);
  string position;

  if (abs(file_change) <= 1 && (abs(rank_change) <= 1)) {
    first_move = false;
    return true;
  }

  if ((abs(file_change) == 2) && (rank_change == 0)) {
    if (first_move == true) {
      // Checking for king in check
      for (Board::iterator it = board.begin(); it != board.end(); it++)
	if (board[source_square]->get_colour() != it->second->get_colour())
	  if (it->second->piece_valid_move(it->first, source_square, board, error_code)) {
	    castling = false;
	  }

      if (file_change > 0) {
	if ((board.count(right_side) != 0) && (board[right_side]->get_name_piece() == "Rook")) {
	  if (is_first_move()) {
	    // Checking for pieces between the king and the rook
	    for (char i = source_file + 1; i < MAX_FILE; i++) {
	      position = string(1, i) + string(1, source_rank);
	      if (board.count(position) != 0)
		castling = false;
	    }

	    // Checking if the king moves through a square that is attacked by a piece of the opponent
	    for (char i = source_file + 1; i < MAX_FILE; i++) {
	      position = string(1, i) + string(1, source_rank);
	      for (Board::iterator it = board.begin(); it != board.end(); it++)
		if (board[source_square]->get_colour() != it->second->get_colour())
		  if (it->second->piece_valid_move(it->first, position, board, error_code))
		    castling = false;
	    }
	  }
	  else
	    castling = false;
	}
	else
	  castling = false;
      }
      else if (file_change < 0) {
	if ((board.count(left_side) != 0) && (board[left_side]->get_name_piece() == "Rook")) {
	  if (is_first_move()) {
	    // Checking for pieces between the king and the rook
	    for (char i = source_file - 1; i > MIN_FILE; i--) {
	      position = string(1, i) + string(1, source_rank);
	      if (board.count(position) != 0)
		castling = false;
	    }
	    // Checking if the king moves through a square that is attacked by a piece of the opponent
	    for (char i = source_file - 1; i > MIN_FILE + 1; i--) {
	      position = string(1, i) + string(1, source_rank);
	      for (Board::iterator it = board.begin(); it != board.end(); it++)
		if (board[source_square]->get_colour() != it->second->get_colour())
		  if (it->second->piece_valid_move(it->first, position, board, error_code))
		    castling = false;
	    }
	  }
	  else
	    castling = false;
	}
	else
	  castling = false;
      }
    }
    else
      castling = false;
  }
  else
    castling = false;


  if (castling == true) {
    first_move = false;
    return true;
  }

  error_code = INVALID_KING_MOVE;
  return false;
}
