#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int wking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int next_index;
    for (int i = wking_loc + 11; board[i] == 13; i = next_index){
        next_index = i + 11; // Eliminate direct loop-carried dependence on i; use separate variable
        l = i; // Update l as side effect (RAW: l depends on current i)
    }
    l = (board[wking_loc + 11] == 13) ? l + 11 : wking_loc + 11; // Ensure l reflects correct final state
}
