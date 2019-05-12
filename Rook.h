#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"

class Rook : public Piece {
private:
  bool first_move;

 public:
  Rook(Colour col);
  ~Rook();
  std::string get_piece() override;
  std::string get_name_piece() override;
  bool piece_valid_move(std::string source_square, std::string dest_square, Board board, int& error_code) override;
  bool is_first_move(); // returns true if it is the first move of the piece, false otherwise
  void set_first_move(bool state);
};

#endif
