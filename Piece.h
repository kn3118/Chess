#ifndef PIECE_H
#define PIECE_H

#include "ChessBoard.h"

class Piece {
 protected:
  Colour piece_colour;

 public:
  Piece(Colour col);
  virtual ~Piece() = 0;
  Colour get_colour();
  virtual std::string get_piece() = 0; // pure virtual function aimed to return a string with the symbol of the piece
  virtual std::string get_name_piece() = 0; // pure virtual function aimed to return a string with the name of the piece
  virtual bool piece_valid_move(std::string source_square, std::string dest_square, Board board, int& error_code) = 0;
};

#endif
