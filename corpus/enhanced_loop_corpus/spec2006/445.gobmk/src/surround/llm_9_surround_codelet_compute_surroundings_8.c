#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int *surround_size;
extern char mn[400];
extern int pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (pos = 21; pos < 400; pos++) {
        int cond1 = (board[pos] != 3);
        int cond2 = (mn[pos] == 1);
        int combined = cond1 & cond2;
        *surround_size += combined;
    }
}
