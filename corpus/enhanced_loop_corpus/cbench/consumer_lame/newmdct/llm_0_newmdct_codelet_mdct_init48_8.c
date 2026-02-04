#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern FLOAT8 win[4][36];
extern int i;
extern FLOAT8 max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int j = 0; j < 4; j++) {
    for (i = 0; i < 36; i++) {
        if (j == 0 || j == 1 || j == 3) {
            win[j][i] *= max / 32768;
        }
    }
}
}
