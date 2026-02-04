#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern char active[400];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int depth = 0; depth < 2; depth++) {
        for (k = (19 + 2); k < (19 + 1) * (19 + 1); k++) {
            if (((board[k]) == 1 || (board[k]) == 2) || active[k] != 0)
                continue;
            if ((board[((k) + (19 + 1))] == 0 && active[((k) + (19 + 1))] == 2) || 
                (board[((k) - 1)] == 0 && active[((k) - 1)] == 2) || 
                (board[((k) - (19 + 1))] == 0 && active[((k) - (19 + 1))] == 2) || 
                (board[((k) + 1)] == 0 && active[((k) + 1)] == 2))
                active[k] = 3;
        }
    }
}
