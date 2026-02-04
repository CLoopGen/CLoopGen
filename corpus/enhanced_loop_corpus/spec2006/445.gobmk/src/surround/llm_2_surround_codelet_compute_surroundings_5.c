#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern int delta[8];
extern Intersection board[421];
extern int k;
extern int dpos;
extern char mn[400];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern on 'mn' and reordered condition evaluation
    // Instead of processing sequentially, we access mn with a stride of 2, handling even indices first
    for (dpos = (19 + 2); dpos < (19 + 1) * (19 + 1); dpos += 2)
        if (mn[dpos] == 1 && board[dpos] != 3)
            for (k = 0; k < 4; k++) {
                int neighbor = dpos + delta[k];
                if (!mn[neighbor] && board[neighbor] != 3)
                    mn[neighbor] = 2;
            }
}
