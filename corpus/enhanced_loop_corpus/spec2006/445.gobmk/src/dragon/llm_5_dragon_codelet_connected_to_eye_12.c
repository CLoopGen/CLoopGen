#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern int delta[8];
extern Intersection board[421];
extern int pos;
extern char mx[400];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (pos >= 0) {
        for (k = 0; k < 8; k++) {
            int offset = pos + delta[k];
            if (board[offset] != 3 && offset < 421)
                mx[offset] = 1;
        }
    }
}
