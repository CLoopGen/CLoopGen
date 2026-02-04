#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long x[199];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    long temp = x[99];
    for (j = 100; j > 0; j--) {
        long prev = x[j - 1];
        x[j] = temp;
        temp = prev;
    }
}
