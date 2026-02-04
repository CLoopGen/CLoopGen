#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long *x;
extern int n;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 2; i < n; i += 2) {
        x[i] = 1103515245 * x[i - 1] + 12345;
        if (i + 1 < n) {
            x[i + 1] = 1103515245 * x[i] + 12345;
        }
    }
}
