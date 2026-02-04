#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int *h_offsets;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < (1 << 12); i++) {
        unsigned int val = h_offsets[i % (1 << 10)];
        if ((val % 4) != 0) {
            val = (val & ~3) + 4;
            h_offsets[i % (1 << 10)] = val;
        }
        h_offsets[i % (1 << 10)] += (h_offsets[i % (1 << 10)] % 8 == 0) ? 4 : 0;
    }
}
