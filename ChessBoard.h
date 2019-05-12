#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include<map>

const char MAX_FILE = 'H';
const char MIN_FILE = 'A';
const int MAX_RANK = 8;
const int MIN_RANK = 1;

enum Colour {Black, White};

class Piece;

typedef std::map<std::string, Piece*>Board;

class ChessBoard {
 private:
  Board board;
  Colour playing_colour;
  bool game_ended; // true if game has ended, false otherwise
  bool first_game; // true if first game (just created ChessBoard object), false otherwise (if we reset the board using the same Chessboard object)
  int error_code;

 public:
  ChessBoard();
  ~ChessBoard();
  void resetBoard(); // creates the pieces of the board (in the heap) and produces the original mapping
  void submitMove(std::string source_square, std::string destination_square);
  void print_frame();
  void print_row(int rank);
  void display_board();
  void clean_board(); // deletes the objects (pieces) from the heap and erases the previous mapping
  void switch_colour(); // switches the playing_colour to control whose turn it is
  bool is_valid_move(const std::string source_square, const std::string dest_square);
  bool is_in_check(); // true if the king is in check, false otherwise
  bool cannot_makemove(); // true if there is no valid move for the player, false otherwise
  bool is_castling(std::string source_square, std::string dest_square, Board board); // true if player can perform castling, false otherwise
  void print_error(std::string source_square, std::string dest_square);
};

/* class Piece { */
/*  protected: */
/*   Colour piece_colour; */
/*   bool first_move; */

/*  public: */
/*   Piece(Colour col); */
/*   virtual ~Piece() = 0; */
/*   Colour get_colour(); */
/*   virtual std::string get_piece() = 0; */
/*   virtual std::string get_name_piece() = 0; */
/*   virtual bool piece_valid_move(std::string source_square, std::string dest_square, Board board, int& error_code) = 0; */
/*   bool is_first_move(); */
/* }; */

/* class King : public Piece { */
/*  private: */

/*  public: */
/*   King(Colour col); */
/*   ~King(); */
/*   std::string get_piece() override; */
/*   std::string get_name_piece() override; */
/*   bool piece_valid_move(std::string source_square, std::string dest_square, Board board, int& error_code) override; */
/* }; */

/* class Rook : public Piece { */
/*  private: */

/*  public: */
/*   Rook(Colour col); */
/*   ~Rook(); */
/*   std::string get_piece() override; */
/*   std::string get_name_piece() override; */
/*   bool piece_valid_move(std::string source_square, std::string dest_square, Board board, int& error_code) override; */
/* }; */

/* class Bishop : public Piece { */
/*  private: */

/*  public: */
/*   Bishop(Colour col); */
/*   ~Bishop(); */
/*   std::string get_piece() override; */
/*   std::string get_name_piece() override; */
/*   bool piece_valid_move(std::string source_square, std::string dest_square, Board board, int& error_code) override; */
/* }; */

/* class Queen : public Piece { */
/*  private: */

/*  public: */
/*   Queen(Colour col); */
/*   ~Queen(); */
/*   std::string get_piece() override; */
/*   std::string get_name_piece() override; */
/*   bool piece_valid_move(std::string source_square, std::string dest_square, Board board, int& error_code) override; */
/* }; */

/* class Knight : public Piece { */
/*  private: */

/*  public: */
/*   Knight(Colour col); */
/*   ~Knight(); */
/*   std::string get_piece() override; */
/*   std::string get_name_piece() override; */
/*   bool piece_valid_move(std::string source_square, std::string dest_square, Board board, int& error_code) override; */
/* }; */

/* class Pawn : public Piece { */
/*  private: */

/*  public: */
/*   Pawn(Colour col); */
/*   ~Pawn(); */
/*   std::string get_piece() override; */
/*   std::string get_name_piece() override; */
/*   bool piece_valid_move(std::string source_square, std::string dest_square, Board board, int& error_code) override; */
/* }; */

#endif
