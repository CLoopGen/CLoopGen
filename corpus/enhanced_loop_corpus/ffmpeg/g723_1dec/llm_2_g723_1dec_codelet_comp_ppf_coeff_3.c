#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int temp1;
extern int energy[5];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2, wrapping around using modulo)
    for (i = 0; i < 5; i++) {
        int idx = (i * 2) % 5;  // Access elements with stride 2: 0, 2, 4, 1, 3
        temp1 = (energy[idx] > temp1) ? energy[idx] : temp1;
    }
}
