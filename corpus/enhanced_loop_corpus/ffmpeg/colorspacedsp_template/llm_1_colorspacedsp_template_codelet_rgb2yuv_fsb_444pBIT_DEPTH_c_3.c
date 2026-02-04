#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern int *rnd_scratch[3][2];
extern int x;
extern  int rnd;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (w > 0) {
        for (int i = 0; i < w; i += 2) {
            int limit = (i + 1 < w) ? i + 2 : i + 1;
            for (int j = i; j < limit; j++) {
                rnd_scratch[1][0][j] = rnd;
                rnd_scratch[1][1][j] = rnd;
                rnd_scratch[2][0][j] = rnd;
                rnd_scratch[2][1][j] = rnd;
            }
        }
    }
}
