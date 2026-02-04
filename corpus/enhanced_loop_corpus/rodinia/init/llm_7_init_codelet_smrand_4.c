#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long mrand_list[56];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    long temp[55];
    temp[0] = mrand_list[0];
    for (i = 1; i < 55; i++) {
        temp[i] = (123413 * temp[i - 1]) % 9223372036854775807L;
    }
    for (i = 1; i < 55; i++) {
        mrand_list[i] = temp[i];
    }
}
