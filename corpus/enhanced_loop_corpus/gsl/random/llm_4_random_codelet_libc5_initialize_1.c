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
        if (x[i - 1] >= 0) {
            x[i] = 1103515145 * x[i - 1] + 12345;
        }
    }
}
