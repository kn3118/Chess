#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

class Bishop : public Piece {
 public:
  Bishop(Colour col);
  ~Bishop();
  std::string get_piece() override;
  std::string get_name_piece() override;
  bool piece_valid_move(std::string source_square, std::string dest_square, Board board, int& error_code) override;
};

#endif
