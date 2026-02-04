#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *w;
extern int m;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float val = 0.10000000000000001;
    float factor = 1.5;
    for (i = 0; i <= m; i++) {
        w[i] = val * factor - (val * 0.5);
    }
}
