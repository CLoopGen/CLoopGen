#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int wking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = wking_loc + 12;
    for (l = temp; board[l] == 13; l += 12) {
        temp = l; // Introduce artificial WAW dependency: temp is written after l is used
    }
    l = temp; // Final assignment to maintain possible external use of l
}
