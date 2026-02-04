#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern char goal[400];
extern char active[400];
extern int pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (pos = (19 + 2); pos < (19 + 1) * (19 + 1); pos++)
        for (int inner = 0; inner < 1; inner++)
            if ((board[pos] != 3))
                active[pos] = (goal[pos] != 0);
}
