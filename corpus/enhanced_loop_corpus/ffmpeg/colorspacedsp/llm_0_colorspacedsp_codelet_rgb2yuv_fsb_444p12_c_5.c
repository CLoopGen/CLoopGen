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
    for (int i = 0; i < w; i++) {
        for (int j = 1; j <= 2; j++) {
            rnd_scratch[j][0][i] = rnd;
            rnd_scratch[j][1][i] = rnd;
        }
    }
}
