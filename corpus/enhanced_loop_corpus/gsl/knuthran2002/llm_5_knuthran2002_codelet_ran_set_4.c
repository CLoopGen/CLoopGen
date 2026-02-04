#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long x[199];
extern int j;
extern long ss;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < 100; j++) {
    if (j % 2 == 0) {
        x[j] = ss;
        ss <<= 1;
    } else {
        x[j] = ss ^ 1;
        ss += 3;
    }
    if (ss >= (1L << 29)) {
        ss = (ss & ((1L << 29) - 1)) + 1;
    }
}
}
