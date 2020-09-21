//
//  SnakeLadder.h
//  SnakeAndLadder
//
//  Created by Rahul Jain on 20/09/20.
//  Copyright © 2020 Rahul Jain. All rights reserved.
//

#ifndef SnakeLadder_h
#define SnakeLadder_h

#include "snake.h"
#include "ladder.h"
#include "player.h"
#include <cstdlib>
#include <vector>
#include <iostream>

class SnakeLadder {
    int boardSize = 100;
    std::vector<player> players;
    std::vector<snake> snakes;
    std::vector<ladder> ladders;
    
    int getRandom(int end){
        return rand()%end + 1;
    }
    
    int processSnakes(int currentPosition){
        
        for(int i=0; i<snakes.size(); i++){
            currentPosition = snakes[i].process(currentPosition);
        }
        return currentPosition;
    }
    
    int processLadders(int currentPosition){
        
        for(int i=0; i<ladders.size(); i++){
            currentPosition = ladders[i].process(currentPosition);
        }
        return currentPosition;
    }
    
public:
    SnakeLadder(){
        int numSnakes;
        int numPlayers;
        int numLadders;
        std::cout<<"Enter number of snakes\n";
        std::cin>>numSnakes;
        snakes.resize(numSnakes);
        
        std::cout<<"Enter number of ladders\n";
        std::cin>>numLadders;
        ladders.resize(numLadders);
        
        std::cout<<"Enter number of players\n";
        std::cin>>numPlayers;
        players.resize(numPlayers);
    }
    
    void play(){
        bool won = false;
        
        while(!won){
            for(int i=0; i<players.size(); i++){
                
                int diceRoll = getRandom(6);
                int currentPosition = players[i].getPosition();
                int nextPosition = currentPosition + diceRoll;
                
                while(1){
                    int updatedNextPostion = processSnakes(nextPosition);
                    updatedNextPostion = processLadders(updatedNextPostion);
                    
                    if(nextPosition == updatedNextPostion){
                        nextPosition = updatedNextPostion;
                        break;
                    }
                    else{
                        nextPosition = updatedNextPostion;
                    }
                }
                
                if(nextPosition > boardSize)
                    nextPosition = currentPosition;
                
                std::cout<<players[i].getName()<<" rolled a "<<diceRoll<<" and moved from "<<currentPosition<<" to "<<nextPosition<<"\n";
                
                players[i].setPosition(nextPosition);
                if(players[i].getPosition() == boardSize){
                    std::cout<<players[i].getName()<<" wins the game\n";
                    won = true;
                }
            }
        }
    }
    
};

#endif /* SnakeLadder_h */
