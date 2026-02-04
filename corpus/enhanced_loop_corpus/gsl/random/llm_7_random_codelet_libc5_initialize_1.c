#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long *x;
extern int n;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    long temp = x[0];
    for (i = 1; i < n; i++) {
        temp = 1103515145 * temp + 12345;
        x[i] = temp;
    }
}
