#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char response[41];
extern char chksum[9];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array
    // Use a lookup table for strided indices to simulate indirect addressing
    const int indices[8] = {0, 4, 8, 12, 16, 20, 24, 28};
    for (i = 0; i < 8; i++)
        chksum[i] = response[indices[i]];
}
