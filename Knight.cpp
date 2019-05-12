#include "Knight.h"
#include "errors.h"
#include <iostream>

using namespace std;

Knight::Knight(Colour col) : Piece(col) {}


Knight::~Knight() {}


string Knight::get_piece() { return (piece_colour == White ? "♘" : "♞" ); }


string Knight::get_name_piece() { return "Knight"; }


bool Knight::piece_valid_move(string source_square, string dest_square, Board board, int& error_code) {

  char source_file = source_square.at(0);
  char source_rank = source_square.at(1);
  char dest_file = dest_square.at(0);
  char dest_rank = dest_square.at(1);

  int file_change = dest_file - source_file;
  int rank_change = dest_rank - source_rank;


  if (((abs(file_change) == 2) && (abs(rank_change) == 1)) || ((abs(file_change) == 1) && abs(rank_change) == 2))
    return true;

  error_code = INVALID_KNIGHT_MOVE;
  return false;
}
