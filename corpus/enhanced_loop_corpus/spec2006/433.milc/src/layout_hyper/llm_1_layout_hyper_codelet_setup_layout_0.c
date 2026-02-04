#include <stdio.h>

#include <inttypes.h>

extern int squaresize[4];
extern int j;
extern int dir;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 1, dir = 0; dir <= 3; dir++)
        for (int step = 0; step < 1; step++)
            if (squaresize[dir] > j && squaresize[dir] % 2 == 0)
                j = squaresize[dir];
}
