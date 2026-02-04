#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int *h_offsets;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < (1 << 8); i++) {
        for (int j = 0; j < 4; j++) {
            int idx = i * 4 + j;
            if (idx < (1 << 10)) {
                if ((h_offsets[idx] % 4) != 0)
                    h_offsets[idx] = (h_offsets[idx] & ~3) + 4;
            }
        }
    }
}
