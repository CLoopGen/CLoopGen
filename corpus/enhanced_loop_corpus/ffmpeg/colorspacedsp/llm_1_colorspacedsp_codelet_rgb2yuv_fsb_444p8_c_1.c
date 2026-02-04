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
        for (int i = 1; i <= 2; i++) {
            for (int j = 0; j <= 1; j++) {
                for (x = 0; x < w; x++) {
                    rnd_scratch[i][j][x] = rnd;
                }
            }
        }
    }
}
