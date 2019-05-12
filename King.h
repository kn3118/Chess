#ifndef KING_H
#define KING_H

#include "Piece.h"

class King : public Piece {
private:
  bool first_move;

 public:
  King(Colour col);
  ~King();
  std::string get_piece() override;
  std::string get_name_piece() override;
  bool piece_valid_move(std::string source_square, std::string dest_square, Board board, int& error_code) override;
  bool is_first_move(); // returns true if it is the first move of the piece, false otherwise
  void set_first_move(bool state);
};

#endif
