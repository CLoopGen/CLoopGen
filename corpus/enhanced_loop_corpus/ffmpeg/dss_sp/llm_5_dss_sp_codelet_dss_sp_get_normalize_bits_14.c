#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int val;
extern int max_val;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    max_val = 0;
    for (; val <= 16384 && max_val < 15; ) {
        val *= 2;
        ++max_val;
        if (max_val % 2 == 0) {
            val += 1;
        }
    }
}
