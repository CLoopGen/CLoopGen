#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *w;
extern int m;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    w[0] = 0.10000000000000001;
    for (i = 1; i <= m; i++) {
        w[i] = w[i-1]; // Introduce RAW dependency: each write depends on previous value
    }
}
