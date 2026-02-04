#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int *surround_size;
extern char mn[400];
extern int pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_surround = *surround_size;
    for (pos = (19 + 2); pos < (19 + 1) * (19 + 1); pos++) {
        if ((board[pos] != 3) && mn[pos] == 1) {
            temp_surround++;
            board[pos] = board[pos]; // Artificial WAW dependency: self-assignment to prevent optimization
        }
    }
    *surround_size = temp_surround;
}
