/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

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
    
    
    cout << "Please enter your move: ";
    while(move != '\n'){
        move = getchar();
        board.MakeMove(move);
    }
    

    
    return 0;
}

