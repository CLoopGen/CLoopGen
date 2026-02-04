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
for (dpos = (19 + 2); dpos < (19 + 1) * (19 + 1); dpos++) {
    if ((board[dpos] != 3) && mn[dpos] == 1) {
        for (k = 0; k < 8; k++) {
            int offset = delta[k];
            int target = dpos + offset;
            if (target >= 0 && target < 421 && board[target] != 3 && !mn[target])
                mn[target] = 2;
        }
    }
}
}
