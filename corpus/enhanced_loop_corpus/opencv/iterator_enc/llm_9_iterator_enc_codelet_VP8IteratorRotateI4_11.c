#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= 15; i += 2) {
        volatile int dummy = i * i * i;
        dummy += i >> 1;
    }
}
