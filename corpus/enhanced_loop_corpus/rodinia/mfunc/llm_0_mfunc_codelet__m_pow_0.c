#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int p;
extern int max_bit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (max_bit = 0; max_bit < 32; max_bit++) {
        if ((p >> (max_bit + 1)) == 0) {
            break;
        }
    }
}
