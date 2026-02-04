#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int *h_offsets;
extern int *sizes;
extern int *nullElements;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < (1 << 10); i++) {
        int sum = h_offsets[i] + nullElements[i];
        if (sum % 8 == 0) {
            sizes[i] = sum / 4;
        } else if (sum > 0) {
            sizes[i] = (sum + 2) / 4;
        } else {
            continue;
        }
    }
}
