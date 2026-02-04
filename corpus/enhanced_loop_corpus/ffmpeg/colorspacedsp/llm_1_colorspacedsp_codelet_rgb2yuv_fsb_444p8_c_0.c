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
        for (int i = 0; i < 1; i++) {
            for (int j = 0; j < w; j++) {
                rnd_scratch[0][0][j] = rnd;
                rnd_scratch[0][1][j] = rnd;
            }
        }
    }
}
