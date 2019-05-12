#include "Piece.h"

Piece::Piece(Colour col) : piece_colour(col) {}


Piece::~Piece() {}


Colour Piece::get_colour() { return piece_colour; }
