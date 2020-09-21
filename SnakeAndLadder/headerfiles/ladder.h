//
//  ladder.h
//  SnakeAndLadder
//
//  Created by Rahul Jain on 20/09/20.
//  Copyright © 2020 Rahul Jain. All rights reserved.
//

#ifndef ladder_h
#define ladder_h

class ladder {
    int start;
    int end;
public:
    ladder(){
        std::cout<<"Enter start and end position for ladder\n";
        std::cin>>start>>end;
    }
    
    int process(int currentPosition){
        if(currentPosition == start)
            return end;
        return currentPosition;
    }
};

#endif /* ladder_h */
