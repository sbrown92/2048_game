/* 
 * File:   Board.cpp
 * Author: Sam
 * 
 * Created on October 6, 2016, 5:27 PM
 */

#include "Board.h"

Board::Board() {
    int t = 1;
    for(int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < WIDTH; j++){ 
            b[i][j] = 0;
        }
    }
    

    gameWon = false;
    spacesLeft = true;
    
    PrintBoard();
}

Board::Board(const Board& orig) {
    for(int i = 0; i < HEIGHT - 1; i++){
        for(int j = 0; j < WIDTH - 1; j++){
            b[i][j] = orig.b[i][j];
        }
    }
    
    gameWon = orig.gameWon;
    spacesLeft = orig.spacesLeft;
}

Board::~Board() {
}

void Board::MakeMove(char direction){
    int target = 1;
    switch(direction){
        case 'w': case 'W':
            for(int i = 0; i < WIDTH; i++){
                for(int j = 0; j < HEIGHT; j++){
                    if(b[j][i] != 0){
                        if(target == 1 | target != b[j][i]){
                            target = b[j][i];
                            //std::cout<<target<<std::endl;
                        }
                        while(b[j-1][i] == 0 && j >= 1){
                            b[j-1][i] = b[j][i];
                            b[j][i] = 0;
                            j--;
                        }
                        if(b[j-1][i] == target){
                            b[j-1][i] += target;
                            b[j][i] = 0;
                            target = 1;
                        }
                    }
                    //std::cout<<"Target: " << target << std::endl;
                }
                target = 1;
                //std::cout<<target<<std::endl;
            }
            break;
        case 'a': case 'A':
            for(int i = 0; i < HEIGHT; i++){
                for(int j = 0; j < WIDTH; j++){
                    if(b[i][j] != 0){
                        if(target == 1 || target != b[i][j]){
                            target = b[i][j];
                            //wstd::cout<<target<<std::endl;
                        }
                        while(b[i][j-1] == 0 && j > 0){
                            b[i][j-1] = b[i][j];
                            b[i][j] = 0;
                            j--;
                        }
                        if(b[i][j-1] == target){
                            b[i][j-1] += target;
                            b[i][j] = 0;
                            target = 1;
                        }
                    }
                }
                target = 1;
            }
            break;
        case 's': case 'S':
            for(int i = 0; i < WIDTH; i++){
                for(int j = HEIGHT-1; j >= 0; j--){
                    if(b[j][i] != 0){
                        if(target == 1 || target != b[j][i]){
                            target = b[j][i];
                            //std::cout<<"\nnew target: " << target<<std::endl;
                        }
                        while(b[j+1][i] == 0 &&j < HEIGHT - 1){
                            b[j + 1][i] = b[j][i];
                            b[j][i] = 0;
                            j++;
                           
                        }
                        if(b[j+1][i] == target && j < HEIGHT - 1){
                            //std::cout<<"Combine Called" << std::endl;
                            b[j+1][i] += target;
                            b[j][i] = 0;
                            target = 1;
                            
                        }
                    }
                }
                target = 1;
            }
            break;
        case 'd': case 'D':
            for(int i = 0; i < HEIGHT; i++){
                for(int j = WIDTH - 1; j >= 0; j--){
                    if(b[i][j] != 0){
                        if(target == 1 || target != b[i][j]){
                            target = b[i][j];
                        }
                        while(b[i][j+1] == 0 && j < WIDTH-1){
                            b[i][j+1] = b[i][j];
                            b[i][j] = 0;
                            j++;
                        }
                        if(b[i][j+1] == target && j < WIDTH - 1){
                            b[i][j + 1] += b[i][j];
                            b[i][j] = 0;
                            target = 1;
                        }
                    }
                }
                target = 1;
            }
            break;
            // Write Default Case. 
    }
    
    
    
}

bool Board::SpacesLeft(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if((b[i][j] == 0) || (b[i + 1][j] == b[i][j]) || (b[i][j + 1] == b[i][j])){
                return true;
            } else {
                return false;
            }
        }
    }
    
    return false;
}

bool Board::GameIsNotDone(){
    if(SpacesLeft() && !ScoreIsReached()){
        return true;
    } else {
        return false;
    }
}

bool Board::ScoreIsReached(){
    for(int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < WIDTH; j++){
            if(b[i][j] == 2048){
                return true;
            }
        }
    }
    return false;
}
/*
 * TODO Look into better function that rand.*/
void Board::PlaceRandomTile(){
    srand(time(NULL));
    bool found = false;
    int x, y;
    while(!found){
        x = rand() % 4;
        y = rand() % 4;
        int val = rand() % 5;
        if(b[x][y] == 0){
            if(val >= 3){
                b[x][y] = 4;
            } else {
                b[x][y] = 2;
            }
            found = true;
        }
    }
    
}

/*
 * TODO: Write helper function to center the numbers. 
 */
void Board::PrintBoard(){
    std::cout << std::endl <<  "+  -  +  -  +  -  +  -  +" << std::endl;
    for(int i = 0; i < HEIGHT; i++){
        std::cout<<"| ";
        for(int j = 0; j < WIDTH; j++){
            std::printf("%-3d | ", b[i][j]);
        }
        std::cout << std::endl <<  "+  -  +  -  +  -  +  -  +" << std::endl;
    }
}
