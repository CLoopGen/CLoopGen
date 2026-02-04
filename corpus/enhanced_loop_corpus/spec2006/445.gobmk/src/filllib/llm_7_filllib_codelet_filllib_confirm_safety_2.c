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
    // Eliminate early break to remove loop-carried control dependency and make loop fully sequential
    // Introduce RAW dependency via cumulative update of apos (though only last relevant write matters)
    int found = 0;
    for (k = 0; k < 4; k++) {
        Intersection neighbor = board[move + delta[k]];
        if (!found && neighbor == color) {
            apos = move + delta[k];  // RAW on 'found' and 'neighbor'
            found = 1;
        }
    }
    // Loop now has loop-carried dependency through 'found', making it non-breakable and serial
}
