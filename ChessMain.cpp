#include "ChessBoard.h"
#include <iostream>

using namespace std;

int main() {

    cout << "===========================" << endl;
    cout << "Testing the Chess Engine" << endl;
    cout << "===========================" << endl;
    cout << endl;


    ChessBoard cb;
    cout << endl;

    /*        
   //First game that has checks and a checkmate at the end with two
   // moves trying to happen after the game is finished
    cb.submitMove("E2", "E4");
    cout << endl;
    cb.submitMove("B8", "C6");
    cout << endl;
    cb.submitMove("D2", "D4");
    cout << endl;
    cb.submitMove("E7", "E5");
    cout << endl;
    cb.submitMove("G1", "F3");
    cout << endl;
    cb.submitMove("E5", "D4");
    cout << endl;
    cb.submitMove("F3", "D4");
    cout << endl;
    cb.submitMove("G8", "F6");
    cout << endl;
    cb.submitMove("B1", "C3");
    cout << endl;
    cb.submitMove("F8", "B4");
    cout << endl;
    cb.submitMove("D4", "C6");
    cout << endl;
    cb.submitMove("B7", "C6");
    cout << endl;
    cb.submitMove("F1", "D3");
    cout << endl;
    cb.submitMove("D7", "D5");
    cout << endl;
    cb.submitMove("E4", "D5");
    cout << endl;
    cb.submitMove("F6", "D5");
    cout << endl;
    cb.submitMove("E1", "G1");
    cout << endl;
    cb.submitMove("D5", "C3");
    cout << endl;
    cb.submitMove("B2", "C3");
    cout << endl;
    cb.submitMove("B4", "C3");
    cout << endl;
    cb.submitMove("C1", "A3");
    cout << endl;
    cb.submitMove("C3", "A1");
    cout << endl;
    cb.submitMove("D1", "A1");
    cout << endl;
    cb.submitMove("D8", "G5");
    cout << endl;
    cb.submitMove("A1", "C3");
    cout << endl;
    cb.submitMove("C8", "D7");
    cout << endl;
    cb.submitMove("F1", "E1");
    cout << endl;
    cb.submitMove("E8", "D8");
    cout << endl;

    cb.submitMove("F2", "F4");
    cout << endl;
    cb.submitMove("G5", "F6");
    cout << endl;
    cb.submitMove("C3", "F6");
    cout << endl;
    cb.submitMove("G7", "F6");
    cout << endl;
    cb.submitMove("A3", "E7");
    cout << endl;
    cb.submitMove("D8", "E8");
    cout << endl;
    cb.submitMove("E7", "F6");
    cout << endl;
    cb.submitMove("D7", "E6");
    cout << endl;
    cb.submitMove("F6", "H8");
    cout << endl;
    cb.submitMove("A8", "D8");
    cout << endl;
    cb.submitMove("F4", "F5");
    cout << endl;
    cb.submitMove("A7", "A6");
    cout << endl;
    cb.submitMove("F5", "E6");
    cout << endl;
    cb.submitMove("A6", "A5");
    cout << endl;
    cb.submitMove("E6", "F7");
    cout << endl;
    cb.submitMove("E8", "D7");
    cout << endl;
    cb.submitMove("H8", "D4");
    cout << endl;
    cb.submitMove("A5", "A4");
    cout << endl;
    cb.submitMove("D4", "C5");
    cout << endl;
    cb.submitMove("A4", "A3");
    cout << endl;
    cb.submitMove("D3", "F5"); // Black is in Checkmate
    cout << endl;
    cb.submitMove("E8", "A8"); // Not allowed since game is finished
    cout << endl;
    cb.submitMove("D7", "D6"); // Not allowed since game is finished
    cout << endl;
    */
    
    /*    
    cb.submitMove("E2", "E4");
    cb.submitMove("E7", "E5");
    cb.submitMove("G1", "F3");
    cb.submitMove("B8", "C6");
    cb.submitMove("F1", "B5");
    cb.submitMove("A7", "A6");
    cb.submitMove("E1", "G1");
    cout << endl;
    cb.resetBoard();

    // testing white Queenside castle - should work
    cb.submitMove("B1", "C3");
    cb.submitMove("B8", "C6");
    cb.submitMove("B2", "B3");
    cb.submitMove("D7", "D6");
    cb.submitMove("C1", "B2");
    cb.submitMove("C8", "F5");
    cb.submitMove("E2", "E3");
    cb.submitMove("G8", "F6");
    cb.submitMove("D1", "F3");
    cb.submitMove("G7", "G6");
    cb.submitMove("E1", "C1");
    cout << endl;

    // testing white Queenside castle fails
    cb.resetBoard();
    cb.submitMove("B1", "C3");
    cb.submitMove("B8", "C6");
    cb.submitMove("B2", "B3");
    cb.submitMove("D7", "D6");
    cb.submitMove("C1", "B2");
    cb.submitMove("C8", "G4");
    cb.submitMove("E2", "E4");
    cb.submitMove("G8", "F6");
    cb.submitMove("D2", "D4");
    cb.submitMove("G7", "G6");
    cb.submitMove("D1", "D3");
    cb.submitMove("A7", "A5");
    cb.submitMove("E1", "C1");
    cout << endl;

    // testing castling
    cb.resetBoard();
    cb.submitMove("E2", "E4");
    cb.submitMove("E7", "E5");
    cb.submitMove("G1", "F3");
    cb.submitMove("B7", "B6");
    cb.submitMove("F1", "A6");
    cb.submitMove("C8", "A6");
    // square on white king's path to kingside castled position is under attack
    cb.submitMove("E1", "G1");
    cout << endl;

    cb.resetBoard();
    cb.submitMove("E2", "E4");
    cb.submitMove("E7", "E5");
    cb.submitMove("G1", "F3");
    cb.submitMove("D8", "G5");
    cb.submitMove("F1", "A6");
    cb.submitMove("G5", "E3");
    // white king attempts to castle kingside  while in check
    cb.submitMove("E1", "G1");
    cout << endl;

    cb.resetBoard();
    cb.submitMove("E2", "E4");
    cb.submitMove("D7", "D5");
    cb.submitMove("A2", "A3");
    cb.submitMove("C8", "G4");
    cb.submitMove("D1", "G4");
    cb.submitMove("D8", "D6");
    cb.submitMove("F1", "D3");
    cb.submitMove("B8", "C6");
    cb.submitMove("A3", "A4");
    // queenside castle king position under thread
    cb.submitMove("E8", "C8");
    cout << endl;

    cb.resetBoard();
    cb.submitMove("E2", "E4");
    cout << endl;
    cb.submitMove("D7", "D5");
    cout << endl;
    cb.submitMove("A2", "A3");
    cout << endl;
    cb.submitMove("C8", "G4");
    cout << endl;
    cb.submitMove("D1", "G4");
    cout << endl;
    cb.submitMove("D8", "D6");
    cout << endl;
    cb.submitMove("G4", "H5");
    cout << endl;
    cb.submitMove("B8", "C6");
    cout << endl;
    cb.submitMove("A3", "A4");
    cout << endl;

    cb.submitMove("E8", "D8");
    cout << endl;
    cb.submitMove("H5", "H6");
    cb.submitMove("D8", "E8");
    cb.submitMove("H6", "H5");
    // castle shouldn't work since the king has already moved
    cb.submitMove("E8", "C8");
    */
    /*
    cb.submitMove("E2", "E4");
    cout << endl;
    cb.submitMove("E7", "E5");
    cout << endl;
    cb.submitMove("E1", "E2");
    cout << endl;
    cb.submitMove("F8", "C5");
    cout << endl;
    cb.submitMove("E2", "E3"); // White king steps into check
    cout << endl;

    cb.resetBoard();

    cb.submitMove("E2", "E4");
    cout << endl;
    cb.submitMove("E7", "E6");
    cout << endl;
    cb.submitMove("D1", "E2");
    cout << endl;
    cb.submitMove("D8", "F6");
    cout << endl;
    cb.submitMove("A2", "A3");
    cout << endl;
    cb.submitMove("F6", "E5");
    cout << endl;
    cb.submitMove("H2", "H3");
    cout << endl;
    cb.submitMove("E5", "E4");
    cout << endl;
    cb.submitMove("E2", "F3");  // White Queen is pinned
    cout << endl;

    cb.resetBoard();

    cb.submitMove("E2", "E4");
    cout << endl;
    cb.submitMove("E7", "E6");
    cout << endl;
    cb.submitMove("A2", "A4");
    cout << endl;
    cb.submitMove("D8", "F6");
    cout << endl;
    cb.submitMove("A1", "A3");
    cout << endl;
    cb.submitMove("F6", "E5");
    cout << endl;
    cb.submitMove("A3", "E3");
    cout << endl;
    cb.submitMove("E5", "E4");
    cout << endl;
    cb.submitMove("E3", "A3"); // White Rook is pinned
    cout << endl;

    cb.resetBoard();

    cb.submitMove("E2", "E4");
    cout << endl;
    cb.submitMove("E7", "E6");
    cout << endl;
    cb.submitMove("F1", "E2");
    cout << endl;
    cb.submitMove("D8", "F6");
    cout << endl;
    cb.submitMove("A2", "A3");
    cout << endl;
    cb.submitMove("F6", "E5");
    cout << endl;
    cb.submitMove("H2", "H3");
    cout << endl;
    cb.submitMove("E5", "E4");
    cout << endl;
    cb.submitMove("E2", "F3"); // White Bishop is pinned
    cout << endl;

    cb.resetBoard();

    cb.submitMove("D2", "D4");
    cout << endl;
    cb.submitMove("E7", "E6");
    cout << endl;
    cb.submitMove("B1", "C3");
    cout << endl;
    cb.submitMove("F8", "B4");
    cout << endl;
    cb.submitMove("C3", "D5"); // White Knight is pinned
    cout << endl;

    cb.resetBoard();

    cb.submitMove("E2", "E4");
    cout << endl;
    cb.submitMove("E7", "E6");
    cout << endl;
    cb.submitMove("A2", "A3");
    cout << endl;
    cb.submitMove("D8", "F6");
    cout << endl;
    cb.submitMove("H2", "H3");
    cout << endl;
    cb.submitMove("F6", "E5");
    cout << endl;
    cb.submitMove("A3", "A4");
    cout << endl;
    cb.submitMove("D7", "D5");
    cout << endl;
    cb.submitMove("E4", "D5"); // White Pawn is pinned
    cout << endl;

    cb.resetBoard();

    cb.submitMove("E2", "E3");
    cout << endl;
    cb.submitMove("E7", "E5");
    cout << endl;
    cb.submitMove("F1", "C4");
    cout << endl;
    cb.submitMove("E8", "E7");
    cout << endl;
    cb.submitMove("A2", "A3");
    cout << endl;
    cb.submitMove("E7", "E6"); // Black King steps into check
    cout << endl;

    cb.resetBoard();

    cb.submitMove("E2", "E3");
    cout << endl;
    cb.submitMove("E7", "E5");
    cout << endl;
    cb.submitMove("D1", "H5");
    cout << endl;
    cb.submitMove("D8", "E7");
    cout << endl;
    cb.submitMove("H5", "E5");
    cout << endl;
    cb.submitMove("E7", "D8"); // Black Queen is pinned
    cout << endl;

    cb.resetBoard();

    cb.submitMove("E2", "E3");
    cout << endl;
    cb.submitMove("D7", "D5");
    cout << endl;
    cb.submitMove("H2", "H3");
    cout << endl;
    cb.submitMove("A7", "A5");
    cout << endl;
    cb.submitMove("A2", "A3");
    cout << endl;
    cb.submitMove("A8", "A6");
    cout << endl;
    cb.submitMove("B2", "B3");
    cout << endl;
    cb.submitMove("A6", "C6");
    cout << endl;
    cb.submitMove("F1", "B5");
    cout << endl;
    cb.submitMove("C6", "A6"); // Black Rook is pinned (diagonally)
    cout << endl;

    cb.resetBoard();

    cb.submitMove("E2", "E3");
    cout << endl;
    cb.submitMove("D7", "D5");
    cout << endl;
    cb.submitMove("D1", "H5");
    cout << endl;
    cb.submitMove("A7", "A5");
    cout << endl;
    cb.submitMove("H5", "D5");
    cout << endl;
    cb.submitMove("E7", "E5");
    cout << endl;
    cb.submitMove("B2", "B3");
    cout << endl;
    cb.submitMove("D8", "F6");
    cout << endl;
    cb.submitMove("B1", "C3");
    cout << endl;
    cb.submitMove("F8", "D6");
    cout << endl;
    cb.submitMove("A2", "A3");
    cout << endl;
    cb.submitMove("E8", "D8"); // King is moved here
    cout << endl;
    cb.submitMove("A3", "A4");
    cout << endl;
    cb.submitMove("D6", "F8"); // Black Bishop is pinned
    cout << endl;

    cb.resetBoard();

    cb.submitMove("E2", "E3");
    cout << endl;
    cb.submitMove("D7", "D5");
    cout << endl;
    cb.submitMove("D1", "H5");
    cout << endl;
    cb.submitMove("A7", "A5");
    cout << endl;
    cb.submitMove("H5", "D5");
    cout << endl;
    cb.submitMove("E7", "E5");
    cout << endl;
    cb.submitMove("B2", "B3");
    cout << endl;
    cb.submitMove("B8", "C6");
    cout << endl;
    cb.submitMove("F1", "B5");
    cout << endl;
    cb.submitMove("C6", "D4"); // Black Knight is pinned
    cout << endl;

    cb.resetBoard();

    cb.submitMove("E2", "E3");
    cout << endl;
    cb.submitMove("D7", "D5");
    cout << endl;
    cb.submitMove("D1", "E2");
    cout << endl;
    cb.submitMove("E8", "D7");
    cout << endl;
    cb.submitMove("E2", "D3");
    cout << endl;
    cb.submitMove("G8", "F6");
    cout << endl;
    cb.submitMove("E3", "E4");
    cout << endl;
    cb.submitMove("D5", "E4"); // Black Pawn is pinned
    cout << endl;
    */
    /*
    // Another stalemate game
    cb.resetBoard();
    cb.submitMove("E2", "E3");
    cb.submitMove("A7", "A5");
    cb.submitMove("D1", "H5");
    cb.submitMove("A8", "A6");
    cb.submitMove("H5", "A5");
    cb.submitMove("H7", "H5");
    cb.submitMove("H2", "H4");
    cb.submitMove("A6", "H6");
    cb.submitMove("A5", "C7");
    cb.submitMove("F7", "F6");
    cb.submitMove("C7", "D7");
    cb.submitMove("E8", "F7");
    cb.submitMove("D7", "B7");
    cb.submitMove("D8", "D3");
    cb.submitMove("B7", "B8");
    cb.submitMove("D3", "H7");
    cb.submitMove("B8", "C8");
    cb.submitMove("F7", "G6");
    cb.submitMove("C8", "E6");
    cb.submitMove("F", "F5");
    */
    // Stalemate game
/*   cb.resetBoard ();
    cb.submitMove ("D2", "D4");
    cb.submitMove ("E7", "E5");
    cb.submitMove ("D1", "D2");
    cb.submitMove ("E5", "E4");
    cb.submitMove ("D2", "F4");
    cb.submitMove ("F7", "F5");
    cb.submitMove ("H2", "H3");
    cb.submitMove ("F8", "B4");
    cb.submitMove ("B1", "D2");
    cb.submitMove ("D7", "D6");
    cb.submitMove ("F4", "H2");
    cb.submitMove ("C8", "E6");
    cb.submitMove ("A2", "A4");
    cb.submitMove ("D8", "H4");
    cb.submitMove ("A1", "A3");
    cb.submitMove ("C7", "C5");
    cb.submitMove ("A3", "G3");
    cb.submitMove ("F5", "F4");
    cb.submitMove ("F2", "F3");
    cb.submitMove ("E6", "B3");
    cb.submitMove ("D4", "D5");
    cb.submitMove ("B4", "A5");
    cb.submitMove ("C2", "C4");
    cb.submitMove ("E4", "E3");
    cout << endl;
*/
/*
    // Short Checkmate game with Black in checkmate
    cb.resetBoard();
    cb.submitMove ("E2", "E4");
    cb.submitMove ("E7", "E5");
    cb.submitMove ("D1", "H5");
    cb.submitMove ("B8", "C6");
    cb.submitMove ("F1", "C4");
    cb.submitMove ("G8", "F6");
    cb.submitMove ("H5", "F7");
    cout << endl;
*/
/*
    // Shortest Checkmate game with White in checkmate
    cb.submitMove ("F2", "F3");
    cb.submitMove ("E7", "E5");
    cb.submitMove ("G2", "G4");
    cb.submitMove ("D8", "H4");
    cout << endl;
*/
/*
    cb.submitMove ("B2", "B4");
    cb.submitMove ("G7", "G5");
    cb.submitMove ("B4", "B6"); //Error
    cb.submitMove ("B4", "A5"); //Error
    cb.submitMove ("B4", "A6"); //Error
    cb.submitMove ("A2", "A3");
    cb.submitMove ("G5", "G3"); //Error
    cb.submitMove ("G5", "H6"); //Error
    cb.submitMove ("G5", "H7"); //Error
    cb.submitMove ("H7", "H6");
    cb.submitMove ("A3", "A5"); //Error
    cb.submitMove ("A3", "A2"); //Error
    cb.submitMove ("A3", "B3"); //Error
    cb.submitMove ("C2", "C4");
    cb.submitMove ("H6", "H4"); //Error
    cb.submitMove ("H6", "H7"); //Error
    cb.submitMove ("H6", "H8"); //Error
    cb.submitMove ("H6", "G7"); //Error
    cb.submitMove ("D7", "D5");
    cb.submitMove ("C4", "C5");
    cb.submitMove ("D5", "C4"); //Error
    cb.submitMove ("E7", "E5");
    cb.submitMove ("C5", "D5"); //Error
    cb.submitMove ("C5", "D6"); //Error
    cb.submitMove ("C5", "C6");
    cb.submitMove ("E5", "C4"); //Error
    cb.submitMove ("E5", "E4");
    cb.submitMove ("C6", "C7"); //Error
    cb.submitMove ("C6", "B7");
    cb.submitMove ("H6", "H5");
    cb.submitMove ("D2", "D4");
    cb.submitMove ("H5", "H4");
    cb.submitMove ("G2", "G4");
    cb.submitMove ("E4", "D3"); //Error
*/
    /*
    // Invalid file and rank representation
    cb.submitMove ("A", "B");
    cb.submitMove ("ABC", "DEF");
    cb.submitMove ("A5H", "B6H");
    cb.submitMove ("This is total madness", "I can't believe it");

    // Source/Dest not valid
    cb.submitMove ("J9", "H8");
    cb.submitMove ("2D", "4D");
    cb.submitMove ("A1", "H0");

    // Empty Square
    cb.submitMove ("G3", "G4");

    // Wrong player's turn (Currently white's turn);
    cb.submitMove ("F7", "F6");
    */
    /*
    // General input checks
    cb.submitMove("E2", "E4");
    cout << endl;
    cb.submitMove("D4", "H6"); // No piece error
    cout << endl;
    cb.submitMove("D2", "D2"); // Same source and destination
    cout << endl;
    cb.submitMove("D78", "D6"); //Incorrect input
    cout << endl;
    cb.submitMove("7D", "D6"); //Incorrect input
    cout << endl;
    cb.submitMove("D2", "66"); //Incorrect input
    cout << endl;
    
    //Pawn testing
    cb.resetBoard();
    cb.submitMove("D2", "D4");
    cout << endl;
    cb.submitMove("D7", "D5");
    cout << endl;
    cb.submitMove("D4", "D5"); // Cannot move as occupied by enemy piece in front
    cout << endl;
    cb.submitMove("C2", "C4");
    cout << endl;
    cb.submitMove("A7", "A6");
    cout << endl;
    cb.submitMove("A2", "A3");
    cout << endl;
    cb.submitMove("A6", "A4"); // Cannot move 2 steps after moving already
    cout << endl;
    cb.submitMove("A6", "A5");
    cout << endl;
    cb.submitMove("B2", "B3");
    cout << endl;
    cb.submitMove("A5", "A4");
    cout << endl;
    cb.submitMove("B3", "C4"); //Contains a friendly piece
    cout << endl;
    cb.submitMove("B3", "A4");
    cout << endl;

    // Rook testing
    cb.submitMove("A8", "E8"); // Shouldn't work - friendly king in the way
    cout << endl;
    cb.submitMove("A8", "B3"); // Error
    cout << endl;
    cb.submitMove("A8", "C4"); // Error
    cout << endl;
    cb.submitMove("A8", "A4");
    cout << endl;

    //Knight testing
    cb.submitMove("B1", "B3"); // Error
    cout << endl;
    cb.submitMove("G1", "E2");// Shouldn't work - friendly piece
    cout << endl;
    cb.submitMove("G1", "F3");
    cout << endl;

    cb.submitMove("A4", "E4"); //Rook error
    cb.submitMove("A4", "B5"); //Rook error
    cb.submitMove("A4", "A5");
    cb.submitMove("A1", "C1"); //Rook error
    cb.submitMove("B1", "C3");
    cb.submitMove("A5", "D5");//Rook error
    cb.submitMove("A5", "A4");
    cb.submitMove("C3", "A4");
    cout << endl;

    // Bishop testing
    cb.submitMove("C8", "C6"); // Error
    cb.submitMove("C8", "E6");
    cb.submitMove("C1", "C3");//Error
    cb.submitMove("C1", "E4");//Error
    cb.submitMove("C1", "A3");//Error
    cb.submitMove("A4", "C3");
    cb.submitMove("B8", "B6");//Error
    cb.submitMove("B8", "D7");
    cb.submitMove("C3", "D1");//Error
    cb.submitMove("C3", "B1");
    cb.submitMove("D7", "B8");
    cb.submitMove("B1", "D2");
    cb.submitMove("E6", "D5");//Error
    cb.submitMove("E6", "B3");//Error

    // King testing
    cb.submitMove("E8", "F8");//Error
    cb.submitMove("E8", "E6"); //Error
    cb.submitMove("E8", "D7");
    cb.submitMove("D1", "D5");
    cout << endl;

    // Queen testing
    cb.submitMove("D1", "D4"); //Error
    cb.submitMove("D1", "D3"); //Error
    cb.submitMove("D1", "A4"); // Black is in check

    cb.submitMove("B8", "A6");//Error - moving a piece that doesn't remove the check
    cb.submitMove("D7", "C8");
    cout << endl;

    // Castling
    cb.submitMove("E1", "G1"); // Error
    cb.submitMove("E1", "C1"); // Error

    cb.submitMove("C1", "B2");
    cb.submitMove("H7", "H6");
    cb.submitMove("G2", "G3");
    cb.submitMove("H6", "H5");

    //Knight testing
    cb.submitMove("F3", "D2");//Error
    cb.submitMove("F3", "F5");//Error
    cb.submitMove("F3", "H5");//Error
    cb.submitMove("F3", "F3");//Error
    cb.submitMove("F3", "G4");//Error
    cb.submitMove("F3", "E3");//Error

    //Queen testing
    cb.submitMove("A4", "B6");//Error
    cb.submitMove("A4", "A3");//Error
    cb.submitMove("A4", "A2");//Error
    cb.submitMove("A4", "H5");//Error
    cb.submitMove("A4", "H4");//Error
    cb.submitMove("a4", "C6");//Error
    cb.submitMove("A4", "C6");
    cb.submitMove("C8", "D7");//Error
    cb.submitMove("D7", "C6");//Error
    cb.submitMove("E6", "D7");
    cb.submitMove("C6", "D7");
    cb.submitMove("C8", "D7");

    //
    cb.submitMove("F1", "G2");
    cb.submitMove("H5", "H4");

    cb.submitMove("A1", "B1");
    cb.submitMove("D7", "C8");
    cb.submitMove("B1", "A1");
    cb.submitMove("C8", "D7");

    //King testing
    cb.submitMove("E1", "C1");//Error since Rook has already moved
    cb.submitMove("E1", "B1");// Error
    cb.submitMove("E1", "E3");//Error
    cb.submitMove("E1", "D2");//Error
    cb.submitMove("E1", "D1");

    cb.submitMove("H4", "H3");
    cb.submitMove("D1", "C1");
    cb.submitMove("D7", "C8");
    cb.submitMove("A1", "B1");
    cb.submitMove("C8", "D7");
    cb.submitMove("B1", "B2");//Error
    cb.submitMove("B1", "B3");//Error
    cb.submitMove("C1", "A1");//Error
    cb.submitMove("C1", "D1");
    cb.submitMove("H3", "G2");
    cb.submitMove("B2", "C3");
    cb.submitMove("D7", "B7");//Error
    cb.submitMove("D7", "F5");//Error
    cb.submitMove("D7", "H7");//Error

    cb.submitMove("G2", "H1");// Pawn promotion
    cb.submitMove("F3", "G5");
    cb.submitMove("H1", "D5");// Error
    cb.submitMove("H1", "E4");// Error if not picking Bishop or Queen
*/
    /*
    cb.submitMove("B1", "C3");
    cb.submitMove("B8", "C6");
    cb.submitMove("B2", "B3");
    cb.submitMove("D7", "D6");
    cb.submitMove("C1", "B2");
    cb.submitMove("C8", "F5");
    cb.submitMove("E2", "E3");
    cb.submitMove("G8", "F6");
    cb.submitMove("D1", "F3");
    cb.submitMove("G7", "G6");
    cb.submitMove("E1", "C1");
    cout << endl;
    */

/*
    //queen side castling (illegal)
    cb.submitMove("E2", "E4");
    cout << endl;
    cb.submitMove("E7", "E5");
    cout << endl;
    cb.submitMove("B1", "C3");
    cout << endl;
    cb.submitMove("G8", "F6");
    cout << endl;
    cb.submitMove("D1", "F3");
    cout << endl;
    cb.submitMove("G7", "G6");
    cout << endl;
    cb.submitMove("B2", "B3");
    cout << endl;
    cb.submitMove("B7", "B6");
    cout << endl;
    cb.submitMove("C1", "A3");
    cout << endl;
    cb.submitMove("F8", "E7");
    cout << endl;
    cb.submitMove("E1", "E2");
    cout << endl;
    cb.submitMove("F6", "E4");
    cout << endl;
    cb.submitMove("E2", "E1");
    cout << endl;
    cb.submitMove("H8", "G8");
    cout << endl;
    cb.submitMove("E1", "C1");
    cout << endl;
*/

    //Silly Testing
    //cb.submitMove("E1", "E3");

    //cb.resetBoard();
/*
    // 4 move checkmate
     cb.submitMove("E2", "E4");
     cout << endl;
     cb.submitMove("E7", "E5");
     cout << endl;
     cb.submitMove("D1", "F3");
     cout << endl;
     cb.submitMove("D7", "D6");
     cout << endl;
     cb.submitMove("F1", "C4");
     cout << endl;
     cb.submitMove("B8", "C6");
     cout << endl;
     cb.submitMove("F3", "F7");
     cout << endl;
*/
/*
    // Castling
    cb.submitMove("E2", "E4");
    cout << endl;
    cb.submitMove("E7", "E5");
    cout << endl;
    cb.submitMove("F1", "C4");
    cout << endl;
    cb.submitMove("G8", "F6");
    cout << endl;
    cb.submitMove("G1", "F3");
    cout << endl;
    cb.submitMove("B8", "C6");
    cout << endl;

    cb.submitMove("E1", "G1");
    cout << endl;
    */
    /*
    cb.submitMove("B7", "B6");

    cb.submitMove("A7", "A6");
    cb.submitMove("A4", "A5");

    cb.submitMove("B7", "B6");
    cb.submitMove("A5", "B6");

    cb.submitMove("C7", "B6");
    cb.submitMove("A1", "A6");

    cb.submitMove("A8", "A6");
    cb.submitMove("B1", "C3");

    cb.submitMove("D8", "C7");
*/
    //cb.submitMove("C7", "C6");
    //cb.submitMove("A2", "A4");

    //cb.submitMove("A3", "E3");

    //cb.submitMove("D7", "D3");

    //cb.submitMove("E3", "B3");

    //cb.submitMove("D8", "E5");



    cb.submitMove("D7", "D6");
    cout << endl;

    cb.submitMove("D4", "H6");
    cout << endl;

    cb.submitMove("D2", "D4");
    cout << endl;

    cb.submitMove("F8", "B4");
    cout << endl;

    cout << "===========================" << endl;
    cout << "Alekhine vs. Vasic (1931)" << endl;
    cout << "===========================" << endl;
    cout << endl;

    cb.resetBoard();
    cout << endl;

    cb.submitMove("E2", "E4");
    cb.submitMove("E7", "E6");
    cout << endl;

    cb.submitMove("D2", "D4");
    cb.submitMove("D7", "D5");
    cout << endl;

    cb.submitMove("B1", "C3");
    cb.submitMove("F8", "B4");
    cout << endl;

    cb.submitMove("F1", "D3");
    cb.submitMove("B4", "C3");
    cout << endl;

    cb.submitMove("B2", "C3");
    cb.submitMove("H7", "H6");
    cout << endl;

    cb.submitMove("C1", "A3");
    cb.submitMove("B8", "D7");
    cout << endl;

    cb.submitMove("D1", "E2");
    cb.submitMove("D5", "E4");
    cout << endl;

    cb.submitMove("D3", "E4");
    cb.submitMove("G8", "F6");
    cout << endl;

    cb.submitMove("E4", "D3");
    cb.submitMove("B7", "B6");
    cout << endl;

    cb.submitMove("E2", "E6");
    cb.submitMove("F7", "E6");
    cout << endl;

    cb.submitMove("D3", "G6");
    cout << endl;


    return 0;
}
