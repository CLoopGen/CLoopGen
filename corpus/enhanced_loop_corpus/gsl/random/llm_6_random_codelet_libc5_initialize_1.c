#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long *x;
extern int n;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (n <= 1) return;
    for (i = 1; i < n; i += 2) {
        if (i + 1 < n) {
            x[i] = 1103515145 * x[i - 1] + 12345;
            x[i + 1] = 1103515145 * x[i] + 12345;
        } else {
            x[i] = 1103515145 * x[i - 1] + 12345;
        }
    }
}
