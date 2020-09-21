//
//  Header.h
//  SnakeAndLadder
//
//  Created by Rahul Jain on 20/09/20.
//  Copyright © 2020 Rahul Jain. All rights reserved.
//

#ifndef snake_h
#define snake_h

#include<iostream>

class snake {
    int start;
    int end;
public:
    snake(){
        std::cout<<"Enter start and end position for snake\n";
        std::cin>>start>>end;
    }
    
    int process(int currentPosition){
        if(currentPosition == start)
            return end;
        return currentPosition;
    }
};

#endif /* Header_h */
