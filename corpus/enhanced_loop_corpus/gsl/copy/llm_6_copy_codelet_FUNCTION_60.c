#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t M;
extern  size_t N;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t limit = (M < N) ? M : N;
    int64_t temp = 0;
    for (i = 0; i < limit; i++) {
        temp += i * 2;  // Introduce WAW and RAW dependencies on 'temp'
        temp = temp % 100;  // Loop-carried dependency via 'temp'
    }
}
