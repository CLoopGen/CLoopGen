#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern FLOAT8 win[4][36];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k < 6; k++) {
    FLOAT8 a, b, c;
    int idx1a = 17 - k;
    int idx1b = 9 + k;
    int idx2a = 35 - k;
    int idx2b = 27 + k;

    // Perform three-way swap unrolling across rows 0, 1, and 3 with reduced repetition
    a = win[0][idx1a]; b = win[0][idx1b];
    win[0][idx1a] = b; win[0][idx1b] = a;
    a = win[0][idx2a]; b = win[0][idx2b];
    win[0][idx2a] = b; win[0][idx2b] = a;

    a = win[1][idx1a]; b = win[1][idx1b];
    win[1][idx1a] = b; win[1][idx1b] = a;
    a = win[1][idx2a]; b = win[1][idx2b];
    win[1][idx2a] = b; win[1][idx2b] = a;

    if (k < 4) {
        a = win[3][idx1a]; b = win[3][idx1b];
        win[3][idx1a] = b; win[3][idx1b] = a;
        a = win[3][idx2a]; b = win[3][idx2b];
        win[3][idx2a] = b; win[3][idx2b] = a;
    }

    // Additional computational work to increase arithmetic intensity
    c = a + b * 2.0;
    win[1][k] += c * 0.5;
}
}
