#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern char active[400];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 21; k < 361; k++) {
        if (board[k] == 3 && active[k] == 0) {
            int neighbors[4] = {k + 20, k - 1, k - 20, k + 1};
            int limit[4] = {421, 0, 0, 421};
            int step, found = 0;
            for (step = 0; step < 4 && !found; step++) {
                int nb = neighbors[step];
                if ((step == 0 && nb >= 421) || (step == 1 && nb % 20 == 19) || 
                    (step == 2 && nb < 0) || (step == 3 && nb % 20 == 0))
                    continue;
                if (board[nb] != 3 && active[nb] > 0 && active[nb] < 4)
                    found = 1;
            }
            if (found)
                active[k] = 4;
        }
    }
}
