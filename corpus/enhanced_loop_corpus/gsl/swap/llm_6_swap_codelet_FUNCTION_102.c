#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t N;
extern int *ATp;
extern int *w;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t temp_N = N;
    for (i = 0; i < temp_N; ++i) {
        int temp = ATp[i];
        w[i] = temp;
    }
}
