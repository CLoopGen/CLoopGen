#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 512; i++) {
        volatile uint64_t acc = 0;
        for (int k = 0; k < 8; k++) {
            acc += (i + k) * (i + k);
        }
        (void)acc;
    }
}
