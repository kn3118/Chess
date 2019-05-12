chess: ChessMain.o ChessBoard.o Piece.o King.o Rook.o Bishop.o Queen.o Knight.o Pawn.o
	g++ ChessMain.o ChessBoard.o Piece.o King.o Rook.o Bishop.o Queen.o Knight.o Pawn.o -o chess

ChessMain.o: ChessMain.cpp ChessBoard.h
	g++ -g -Wall -c ChessMain.cpp

ChessBoard.o: ChessBoard.cpp ChessBoard.h errors.h Rook.h Knight.h Bishop.h Queen.h King.h Pawn.h
	g++ -g -Wall -c ChessBoard.cpp

Piece.o: Piece.cpp Piece.h
	g++ -g -Wall -c Piece.cpp

King.o: King.cpp King.h errors.h
	g++ -g -Wall -c King.cpp

Rook.o: Rook.cpp Rook.h errors.h
	g++ -g -Wall -c Rook.cpp

Bishop.o: Bishop.cpp Bishop.h errors.h
	g++ -g -Wall -c Bishop.cpp

Queen.o: Queen.cpp Queen.h errors.h
	g++ -g -Wall -c Queen.cpp

Knight.o: Knight.cpp King.h errors.h
	g++ -g -Wall -c Knight.cpp

Pawn.o: Pawn.cpp Pawn.h errors.h
	g++ -g -Wall -c Pawn.cpp

clean:
	rm -f *.o chess 
