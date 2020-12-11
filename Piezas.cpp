#include "Piezas.h"
#include <vector>
#include <iostream>
/** CLASS Piezas
 * Class for representing a Piezas vertical board, which is roughly based
 * on the game "Connect Four" where pieces are placed in a column and 
 * fall to the bottom of the column, or on top of other pieces already in
 * that column. For an illustration of the board, see:
 *  https://en.wikipedia.org/wiki/Connect_Four
 *
 * Board coordinates [row,col] should match with:
 * [2,0][2,1][2,2][2,3]
 * [1,0][1,1][1,2][1,3]
 * [0,0][0,1][0,2][0,3]
 * So that a piece dropped in column 2 should take [0,2] and the next one
 * dropped in column 2 should take [1,2].
**/


/**
 * Constructor sets an empty board (default 3 rows, 4 columns) and 
 * specifies it is X's turn first
**/
Piezas::Piezas()
{
    turn = X;
    for(int i=0; i<BOARD_COLS; i++){
        std::vector<Piece> p;
        for(int j=0; j<BOARD_ROWS; j++)
            p.push_back(Blank);
        board.push_back(p);
    }
}

/**
 * Resets each board location to the Blank Piece value, with a board of the
 * same size as previously specified
**/
void Piezas::reset()
{
    for(int i=0; i<BOARD_COLS; i++){
        std::vector<Piece> p;
        for(int j=0; j<BOARD_ROWS; j++)
            p.push_back(Blank);
        board.push_back(p);
    }
}

/**
 * Places a piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. dropPiece does 
 * NOT allow to place a piece in a location where a column is full.
 * In that case, placePiece returns Piece Blank value 
 * Out of bounds coordinates return the Piece Invalid value
 * Trying to drop a piece where it cannot be placed loses the player's turn
**/ 
Piece Piezas::dropPiece(int column)
{
    if(column > 4 || column < 0)
	  return Invalid;
    for(int x=0; x<BOARD_ROWS; x++){
        if(board[column][x] == Blank){
            board[column][x] = turn;
            turn = (turn = X) ? O : X;
            return board[column][x];
        }
    }
    turn = (turn = X) ? O : X; //this colum is full, so can not drop, player lose turn
    return Blank;
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece Piezas::pieceAt(int row, int column)
{
    if(row >= BOARD_ROWS || column >= BOARD_COLS || row < 0 || column < 0)
	  return Invalid;
    if(board[column][row])
        return board[column][row];
    else return Blank;
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won ("tie").
 * For a game to be over, all locations on the board must be filled with X's 
 * and O's (i.e. no remaining Blank spaces). The winner is which player has
 * the most adjacent pieces in a single line. Lines can go either vertically
 * or horizontally. If both X's and O's have the same max number of pieces in a
 * line, it is a tie.
**/
Piece Piezas::gameState()
{
    //for(int x=0; x<BOARD_ROWS)
    int X_count=0;
    int O_count=0;
    int x_cur=0, o_cur=0;

    for(int i=0; i< BOARD_COLS; i++){
        //std::vector<Piece> p;
        for(int j=0; j<board[i].size(); j++){
            if(board[i][j]==O){
                o_cur++;
                if(o_cur > O_count)
                    O_count = o_cur;
            }
            else{
                o_cur=0;
            }
            if(board[i][j]==X){
                x_cur++;
                if(x_cur > X_count)
                    X_count = x_cur;
            }
            else{
                x_cur=0;
            }
        }
    }
    for(int i=0; i< BOARD_ROWS; i++){
        //std::vector<Piece> p;
        for(int j=0; j<board[i].size(); j++){
            if(board[i][j]==O){
                o_cur++;
                if(o_cur > O_count)
                    O_count = o_cur;
            }
            else{
                o_cur=0;
            }
            if(board[i][j]==X){
                x_cur++;
                if(x_cur > X_count)
                    X_count = x_cur;
            }
            else{
                x_cur=0;
            }
        }
    }
    if(X_count==O_count)
        return Blank;
    if(X_count>O_count)
        return X;
    if(X_count<O_count)
        return O;

}
