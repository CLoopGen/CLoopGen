#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern unsigned int x;
extern uint8_t *ptr;
extern unsigned int len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index array (simulated with precomputed indices)
    // We create a local index mapping to simulate non-sequential buffer access
    uint32_t *dest = (uint32_t *)ptr;
    for (x = 0; x < len; x++) {
        unsigned int i = x; // direct index into buf
        unsigned int j = len + x; // second segment
        unsigned int k = 2*len + x; // third segment
        dest[i] = (255U << 24) | ((uint32_t)buf[i] << 16) | ((uint32_t)buf[j] << 8) | buf[k];
    }
    // Update ptr to reflect advancement
    ptr += 4 * len;
}
