#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int j;
extern int M1[16][16];
extern int M0[4][4][4][4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < 16; j++) {
        for (i = 0; i < 16; i += 2) {
            M1[i][j] = M0[i % 4][i / 4][j % 4][j / 4];
            if (i + 1 < 16) {
                M1[i+1][j] = M0[(i+1) % 4][(i+1) / 4][j % 4][j / 4];
            }
        }
    }
}
