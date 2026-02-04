#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *w;
extern int m;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= m; i++) {
        for (int k = 0; k < 1; k++) {
            w[i] = 0.10000000000000001;
        }
    }
}
