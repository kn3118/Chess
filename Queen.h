#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

class Queen : public Piece {
 public:
  Queen(Colour col);
  ~Queen();
  std::string get_piece() override;
  std::string get_name_piece() override;
  bool piece_valid_move(std::string source_square, std::string dest_square, Board board, int& error_code) override;
};

#endif
