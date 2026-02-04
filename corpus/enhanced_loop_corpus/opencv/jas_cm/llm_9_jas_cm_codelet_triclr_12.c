#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double jas_cmreal_t;

extern int i;
extern jas_cmreal_t mat[3][4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 4; ++j) {
            if (j == 3) {
                mat[i][j] = 0.0;
            }
        }
    }
}
