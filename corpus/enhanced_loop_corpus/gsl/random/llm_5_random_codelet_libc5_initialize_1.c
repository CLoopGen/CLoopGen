#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long *x;
extern int n;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < n; i++) {
        x[i] = 1103515145 * x[i - 1] + 12345;
        if (x[i] % 2 == 0) {
            i++; // Skip the next iteration by advancing the index
        }
    }
}
