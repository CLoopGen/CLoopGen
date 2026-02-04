#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int len;
extern double alpha;
extern double *x;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len; i++) {
        for (int k = 0; k < 1; k++)
            x[i] *= alpha;
    }
}
