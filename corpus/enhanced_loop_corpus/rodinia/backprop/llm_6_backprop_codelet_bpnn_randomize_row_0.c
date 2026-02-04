#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *w;
extern int m;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp = 0.10000000000000001;
    for (i = 0; i <= m; i++) {
        w[i] = temp;
    }
}
