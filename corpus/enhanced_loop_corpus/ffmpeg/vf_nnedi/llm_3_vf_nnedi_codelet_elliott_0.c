#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *data;
extern  int n;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (iterate from end to start)
    for (i = n - 1; i >= 0; i--) {
        data[i] = data[i] / (1.F + (data[i] >= 0 ? data[i] : -data[i]));
    }
}
