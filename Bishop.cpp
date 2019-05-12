#include "Bishop.h"
#include "errors.h"
#include <iostream>
#include <string>

using namespace std;

Bishop::Bishop(Colour col) : Piece(col) {}


Bishop::~Bishop() {}


string Bishop::get_piece() { return (piece_colour == White ? "♗" : "♝" ); }


string Bishop::get_name_piece() { return "Bishop"; }


bool Bishop::piece_valid_move(string source_square, string dest_square, Board board, int& error_code) {

  bool accept_move = true;
  char source_file = source_square.at(0);
  char source_rank = source_square.at(1);
  char dest_file = dest_square.at(0);
  char dest_rank = dest_square.at(1);

  int file_change = dest_file - source_file;
  int rank_change = dest_rank - source_rank;

  char tmp_path_rank = source_rank;
  string path_file;
  string path_rank;
  string position;


  if (abs(file_change) == abs(rank_change)) {
    if ((file_change > 0) && (rank_change > 0)) {
      for (char i = source_file + 1; i < dest_file; i++) {
	path_file = string(1, i);
	tmp_path_rank += 1;
	path_rank = string(1, tmp_path_rank);
	position = path_file + path_rank;
	if (board.count(position) != 0)
	  accept_move = false;
      }
      if (accept_move == true)
	return true;
}

    if ((file_change > 0) && (rank_change < 0)) {
      for (char i = source_file + 1; i < dest_file; i++) {
	path_file = string(1, i);
	tmp_path_rank -= 1;
	path_rank = string(1, tmp_path_rank);
	position = path_file + path_rank;
	if (board.count(position) != 0)
	  accept_move = false;
      }
      if (accept_move == true)
	return true;
}

    if ((file_change < 0) && (rank_change > 0)) {
      for (char i = source_file - 1; i > dest_file; i--) {
	path_file = string(1, i);
	tmp_path_rank += 1;
	path_rank = string(1, tmp_path_rank);
	position = path_file + path_rank;
	if (board.count(position) != 0)
	  accept_move = false;
      }
      if (accept_move == true)
	return true;
    }

    if ((file_change < 0) && (rank_change < 0)) {
      for (char i = source_file - 1; i > dest_file; i--) {
	path_file = string(1, i);
	tmp_path_rank -= 1;
	path_rank = string(1, tmp_path_rank);
	position = path_file + path_rank;
	if (board.count(position) != 0)
	  accept_move = false;
      }
      if (accept_move == true)
	return true;
    }
  }

  error_code = INVALID_BISHOP_MOVE;
  return false;
}
