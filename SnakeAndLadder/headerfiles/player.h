//
//  player.h
//  SnakeAndLadder
//
//  Created by Rahul Jain on 20/09/20.
//  Copyright © 2020 Rahul Jain. All rights reserved.
//

#ifndef player_h
#define player_h

#include<string>
#include<iostream>

class player {
    int currentPosition;
    std::string name;
public:
    player(){
        currentPosition = 0;
        std::cout<<"Enter name for the Player\n";
        std::cin>>name;
    }
    
    int getPosition(){
        return currentPosition;
    }
    
    std::string getName(){
        return name;
    }
    
    void setPosition(int nextPosition){
        currentPosition = nextPosition;
    }
};

#endif /* player_h */
