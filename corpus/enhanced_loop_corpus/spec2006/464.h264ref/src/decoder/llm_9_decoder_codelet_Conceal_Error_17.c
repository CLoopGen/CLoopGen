#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int j;
extern int resY[16][16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 32; j++) {
            int idx = j % 16;
            resY[idx][i] = 0;
            if (j >= 16) {
                resY[idx][i + 8] = 0;
            }
        }
    }
}
