#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t M;
extern  size_t N;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < ((M) < (N) ? (M) : (N)) * 2; i += 2) {
        volatile size_t x = i * i + i / (i + 1);
    }
}
