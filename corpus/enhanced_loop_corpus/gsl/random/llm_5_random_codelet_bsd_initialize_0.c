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
        long prev = x[i - 1];
        if (prev & 1) {
            x[i] = 1103515245 * prev + 12345;
        } else {
            x[i] = prev + 1;
        }
    }
}
