#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double m[3][3];
extern double X[4];
extern double Z[4];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 6; i += 2) {
        int idx = i / 2;
        m[0][idx] = (i % 3 == 0) ? X[idx] : m[0][idx];
        m[1][idx] = 1.0;
        m[2][idx] = (i % 2 == 0) ? Z[idx] : m[2][idx];
    }
}
