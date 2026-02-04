#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int p;
extern int max_bit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (max_bit = 0; ; max_bit++) {
        temp = p >> (max_bit + 1);  // Introduce temporary to create WAW dependency on temp, remove direct use of expression in condition
        if ((temp) == 0)
            break;
    }
}
