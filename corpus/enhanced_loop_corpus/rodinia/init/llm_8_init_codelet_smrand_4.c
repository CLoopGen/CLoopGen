#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long mrand_list[56];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < 55; i += 2) {
        mrand_list[i] = (123413 * mrand_list[i - 1]) % 9223372036854775807L;
        if (i + 1 < 55) {
            mrand_list[i + 1] = (123413 * mrand_list[i]) % 9223372036854775807L;
        }
    }
}
