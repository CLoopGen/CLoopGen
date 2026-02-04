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
        long temp1 = x[i - 1];
        long temp2 = 1103515145 * temp1;
        long temp3 = temp2 + 12345;
        x[i] = temp3;
    }
}
