#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern FLOAT8 win[4][36];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 35; i >= 0; i--) {
        win[1][i] = 0.;
        if (i > 0) {
            win[1][i-1] = win[1][i]; // Introduce WAW and RAW loop-carried dependency
        }
    }
}
