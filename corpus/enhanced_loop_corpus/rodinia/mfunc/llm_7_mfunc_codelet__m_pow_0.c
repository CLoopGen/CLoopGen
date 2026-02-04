#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int p;
extern int max_bit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_max_bit = 0;
    int shift_val;
    for (; ; local_max_bit++) {
        shift_val = local_max_bit + 1;  // Introduce derived variable to create RAW dependency
        if ((p >> shift_val) == 0) {
            max_bit = local_max_bit;  // Store result only at exit, removing loop-carried dependency on max_bit during iterations
            break;
        }
    }
}
