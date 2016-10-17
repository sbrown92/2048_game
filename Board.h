/* 
 * File:   Board.h
 * Author: Sam Brown
 *
 * Created on October 6, 2016, 5:27 PM
 */

#ifndef BOARD_H
#define BOARD_H

#include<iostream>


const int HEIGHT = 4;
const int WIDTH = 4;
class Board {
public:
    Board();
    Board(const Board& orig);
    virtual ~Board();
    
    void MakeMove(char direction);
    bool GameIsNotDone();
    void PrintBoard();
    
    
private:
    int b[4][4];
    bool gameWon, spacesLeft;
    
    bool ScoreIsReached();
    bool SpacesLeft();
    void CombineSimilarTiles(char direction);
    void PlaceRandomTile();
    
    

};

#endif /* BOARD_H */
