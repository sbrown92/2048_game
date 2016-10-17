/* 
 * File:   main.cpp
 * Author: Sam
 *
 * Created on October 6, 2016, 5:26 PM
 */

#include <cstdlib>
#include <iostream>
#include <termios.h>
#include <unistd.h>
#include "Board.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Board board;
    static struct termios oldT, newT;
    int res = tcgetattr( STDIN_FILENO, &oldT);
    char move = ' ';
    
    newT = oldT;
    newT.c_lflag &= ~(ICANON | ECHO);
    tcsetattr( STDIN_FILENO, TCSANOW, &newT);
    
    while(board.GameIsNotDone()){
        cout << "Please enter your move: " << endl;
        move = getchar();
        board.MakeMove(move);
        
    }

    
    return 0;
}

