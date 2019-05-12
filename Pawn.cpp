#include "Pawn.h"
#include "errors.h"
#include <iostream>

using namespace std;


Pawn::Pawn(Colour col) : Piece(col) { first_move = true; }


Pawn::~Pawn() {}


string Pawn::get_piece() { return (piece_colour == White ? "♙" : "♟" ); }


string Pawn::get_name_piece() { return "Pawn"; }


bool Pawn::is_first_move() { return first_move; }


void Pawn::set_first_move(bool state) { first_move = state; }


bool Pawn::piece_valid_move(string source_square, string dest_square, Board board, int& error_code) {

  char source_file = source_square.at(0);
  char source_rank = source_square.at(1);
  char dest_file = dest_square.at(0);
  char dest_rank = dest_square.at(1);

  int file_change = dest_file - source_file;
  int rank_change = dest_rank - source_rank;

  string down_square = string(1, source_file) + string(1, source_rank - 1);
  string two_squares_down = string(1, source_file) + string(1, source_rank - 2);
  string up_square = string(1, source_file) + string(1, source_rank + 1);
  string two_squares_up = string(1, source_file) + string(1, source_rank + 2);


  if (piece_colour == Black) {
    if ((rank_change == -1) && (file_change == 0) && (board.count(down_square) == 0))
      return true;
    else if ((first_move) && (file_change == 0) && (rank_change == -2)
	     && (board.count(two_squares_down) == 0) && (board.count(down_square) == 0))
      return true;
    else if ((rank_change == -1) && (abs(file_change) == 1) && (board.count(dest_square) != 0))
      return true;
    }

  if (piece_colour == White) {
    if ((rank_change == 1) && (file_change == 0) && (board.count(up_square) == 0))
      return true;
    else if ((first_move) && (file_change == 0) && (rank_change == 2)
	     && (board.count(two_squares_up) == 0) && (board.count(up_square) == 0))
      return true;
    else if ((rank_change == 1) && (abs(file_change) == 1) && (board.count(dest_square) != 0))
      return true;
    }

  error_code = INVALID_PAWN_MOVE;
  return false;

}
