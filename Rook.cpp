#include "Rook.h"
#include "errors.h"
#include <iostream>
#include <string>

using namespace std;

Rook::Rook(Colour col) : Piece(col) { first_move = true; }


Rook::~Rook() {}


string Rook::get_piece() { return (piece_colour == White ? "♖" : "♜" ); }


string Rook::get_name_piece() { return "Rook"; }


bool Rook::is_first_move() { return first_move; }


void Rook::set_first_move(bool state) { first_move = state; }


bool Rook::piece_valid_move(string source_square, string dest_square, Board board, int& error_code) {

  bool accept_move = true;
  char source_file = source_square.at(0);
  char source_rank = source_square.at(1);
  char dest_file = dest_square.at(0);
  char dest_rank = dest_square.at(1);

  int file_change = dest_file - source_file;
  int rank_change = dest_rank - source_rank;

  string path_file;
  string path_rank;
  string position;

  if ((file_change == 0) && (rank_change > 0)) {
    for (int i = source_rank - '0' + 1; i < dest_rank - '0'; i++) {
      path_rank = to_string(i);
      position = string(1, source_file) + path_rank;
      if (board.count(position) != 0)
	accept_move = false;
    }
    if (accept_move == true) {
      first_move = false;
      return true;
    }
  }

  if ((file_change == 0) && (rank_change < 0)) {
    for (int i = source_rank - '0' - 1; i > dest_rank - '0'; i--) {
      path_rank = to_string(i);
      position = string(1, source_file) + path_rank;
      if (board.count(position) != 0)
	accept_move = false;
    }
    if (accept_move == true) {
      first_move = false;
      return true;
    }
  }

  if ((file_change > 0) && (rank_change == 0)) {
    for (char i = source_file + 1; i < dest_file; i++) {
      path_file = string(1, i);
      position = path_file + string(1, source_rank);
      if (board.count(position) != 0)
	accept_move = false;
    }
    if (accept_move == true) {
      first_move = false;
      return true;
    }
  }

  if ((file_change < 0) && (rank_change == 0)) {
    for (char i = source_file - 1; i > dest_file; i--) {
      path_file = string(1, i);
      position = path_file + string(1, source_rank);
      if (board.count(position) != 0)
	accept_move = false;
    }
    if (accept_move == true) {
      first_move = false;
      return true;
    }
  }

  error_code = INVALID_ROOK_MOVE;
  return false;
}
