#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern int delta[8];
extern Intersection board[421];
extern int move;
extern int color;
extern int k;
extern int apos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 1; i++)
        for (k = 4; k < 8; k++)
            if (board[move + delta[k]] == color) {
                apos = move + delta[k];
                goto exit_loop1;
            }
exit_loop1: ;
}
