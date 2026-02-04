#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t M;
extern  size_t N;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int64_t temp = 0;
    for (i = 0; i < ((M) < (N) ? (M) : (N)); i++) {
        temp += i * 2; // Introduce loop-carried dependency: each iteration depends on previous value of temp (WAW and RAW)
    }
    // Prevent unused variable warning by using temp in a benign way
    if (temp < 0) {
        temp = 0;
    }
}
