#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int max;
extern unsigned short count[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int local_count[16];
    for (unsigned int i = 0; i < 16; i++) {
        local_count[i] = count[i];
    }
    for (max = 15; max >= 1; max--) {
        if (local_count[max] == 0) {
            continue;
        } else {
            break;
        }
    }
}
