#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern char active[400];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = (19 + 2); k < (19 + 1) * (19 + 1); k++) {
    if (board[k] != 3) {
        if (active[k] == 0) {
            int neighbor_check = 0;
            if ((board[k + 20] != 3) && (active[k + 20] > 0 && active[k + 20] < 4))
                neighbor_check = 1;
            else if ((board[k - 1] != 3) && (active[k - 1] > 0 && active[k - 1] < 4))
                neighbor_check = 1;
            else if ((board[k - 20] != 3) && (active[k - 20] > 0 && active[k - 20] < 4))
                neighbor_check = 1;
            else if ((board[k + 1] != 3) && (active[k + 1] > 0 && active[k + 1] < 4))
                neighbor_check = 1;

            if (neighbor_check)
                active[k] = 4;
        }
    }
}
}
