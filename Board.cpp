/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Board.cpp
 * Author: Sam
 * 
 * Created on October 6, 2016, 5:27 PM
 */

#include "Board.h"

Board::Board() {
    for(int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < WIDTH; j++){ 
            b[i][j] = 0;
        }
    }
    
    
    b[3][2] = 2;
    b[2][2] = 2;
    b[2][1] = 2;
    b[1][0] = 4;
    b[0][0] = 4;
    
    gameWon = false;
    spacesLeft = true;
    
    PrintBoard();
}

Board::Board(const Board& orig) {
}

Board::~Board() {
}

bool Board::MakeMove(char direction){
    switch(direction){
        case 'w': case 'W':
            for(int i = 0; i < WIDTH; i++){
                for(int j = 0; j < HEIGHT; j++){
                    if(b[j][i] != 0){
                        while(b[j-1][i] == 0 && j >= 1){
                            b[j-1][i] = b[j][i];
                            b[j][i] = 0;
                            j--;
                        }
                    }
                }
            }
            break;
        case 'a': case 'A':
            for(int i = 0; i < HEIGHT; i++){
                for(int j = 0; j < WIDTH; j++){
                    if(b[i][j] != 0){
                        while(b[i][j-1] == 0 && j > 0){
                            b[i][j-1] = b[i][j];
                            b[i][j] = 0;
                            j--;
                        }
                    }
                }
            }
            break;
        case 's': case 'S':
            for(int i = 0; i < WIDTH; i++){
                for(int j = HEIGHT-1; j >= 0; j--){
                    if(b[j][i] != 0){
                        while(j < HEIGHT - 1 && b[j + 1][i] == 0){
                            b[j + 1][i] = b[j][i];
                            b[j][i] = 0;
                            j++;
                        }
                    }
                }
            }
            break;
        case 'd': case 'D':
            for(int i = 0; i < HEIGHT; i++){
                for(int j = WIDTH - 1; j >= 0; j--){
                    if(b[i][j] != 0){
                        while(b[i][j+1] == 0 && j < HEIGHT-1){
                            b[i][j+1] = b[i][j];
                            b[i][j] = 0;
                            j++;
                        }
                    }
                }
            }
            break;
            // Write Default Case. 
    }
    
    PrintBoard();
    
    
    return true;
    
}


void Board::PrintBoard(){
    std::cout << std::endl <<  "+-+-+-+-+" << std::endl;
    for(int i = 0; i < HEIGHT; i++){
        std::cout<<"|";
        for(int j = 0; j < WIDTH; j++){
            std::cout << b[i][j] << "|";
        }
        std::cout << std::endl << "+-+-+-+-+" << std::endl;
    }
}
