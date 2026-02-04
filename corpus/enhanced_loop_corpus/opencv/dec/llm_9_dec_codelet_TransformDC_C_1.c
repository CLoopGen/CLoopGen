#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < 2; ++j) {
    for (i = 0; i < 2; ++i) {
        volatile int acc = 0;
        acc += i + j;
        acc *= acc;
        acc >>= 1;
    }
}
}
