#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long mrand_list[56];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 2; i < 55; i++) {
        int64_t temp1 = (123413 * mrand_list[i - 1]) % 9223372036854775807L;
        int64_t temp2 = (123413 * mrand_list[i - 2]) % 9223372036854775807L;
        mrand_list[i] = (temp1 + temp2) % 9223372036854775807L;
    }
}
