#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *top;
extern int i;
extern uint8_t v[15];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using pointer arithmetic and offset array
    // Simulate indirect access via a fixed offset table (mimicking gather pattern)
    const int offsets[] = {0, 1, 2}; // Base indices used in original computation
    uint8_t *base = top;
    for (i = 0; i < 16 - 2; i++) {
        v[i] = ((base[i + offsets[0]]) + (base[i + offsets[1]]) * 2 + (base[i + offsets[2]]) + 2) >> 2;
    }
}
