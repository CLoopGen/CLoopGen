#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern char active[400];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int size = 19 + 1;
    int limit = size * size;
    // Eliminate potential RAW hazards by preloading and reordering memory accesses
    char temp_active[400];
    Intersection temp_board[421];

    // Local copy to remove immediate data dependencies on global state
    for (int i = 0; i < 421; i++)
        temp_board[i] = board[i];
    for (int i = 0; i < 400; i++)
        temp_active[i] = active[i];

    for (k = 21; k < limit; k++) {
        if (((temp_board[k]) == 1 || (temp_board[k]) == 2) || temp_active[k] != 0)
            continue;
        if ((temp_board[k + size] == 0 && temp_active[k + size] == 2) ||
            (temp_board[k - 1] == 0 && temp_active[k - 1] == 2) ||
            (temp_board[k - size] == 0 && temp_active[k - size] == 2) ||
            (temp_board[k + 1] == 0 && temp_active[k + 1] == 2))
            active[k] = 3;  // Only write back to original array, no loop-carried dependency now
    }
    // All reads are from local copies — eliminates loop-carried data dependencies (RAW/WAR/WAW)
}
