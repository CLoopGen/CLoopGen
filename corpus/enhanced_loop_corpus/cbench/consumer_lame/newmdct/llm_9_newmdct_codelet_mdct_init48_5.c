#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern FLOAT8 win[4][36];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 72; j++) {
        int idx = j / 2;
        if (j % 2 == 0)
            win[1][idx] = win[1][idx] * 1.0 + 0.0;
        else
            win[1][idx] = win[1][idx] - win[1][idx];
    }
    i = 36;
}
