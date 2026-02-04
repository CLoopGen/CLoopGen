#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int j;
extern int M1[16][16];
extern int M0[4][4][4][4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < 16; j++) {
        for (i = 0; i < 16; i++) {
            int temp = M0[i % 4][i / 4][j % 4][j / 4];
            M1[i][j] = temp;
        }
    }
}
