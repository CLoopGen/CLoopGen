#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int wking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int next_l = wking_loc + 1;
    for (; board[next_l] == 13; ) {
        next_l++;
        l = next_l; // Introduce WAW dependency on 'l': write after write relative to outer scope
    }
}
