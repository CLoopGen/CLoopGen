#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long *x;
extern int n;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (n > 1) {
        for (i = 1; i < n; i++) {
            long temp = 1103515245 * x[i - 1] + 12345;
            x[i] = temp;
        }
    }
}
