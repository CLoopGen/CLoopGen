#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int wking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_l = wking_loc + 13;
    for (l = temp_l; board[l] == 13; ) {
        l += 13;
        temp_l = l; // Introduce artificial WAW dependency: writing to temp_l after l is updated
    }
    l = temp_l; // Ensure final value is assigned to shared variable l
}
