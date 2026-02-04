#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AVInteger {
    uint16_t v[8];
} AVInteger;

extern AVInteger a;
extern AVInteger b;
extern int i;
extern int carry;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Reverse consecutive access pattern
    // Access the array from last to first element consecutively
    carry = (carry & 0xFFFF0000) >> 16; // Initialize carry properly
    for (i = 7; i >= 0; i--) {
        carry = (carry >> 16) + a.v[i] - b.v[i];
        a.v[i] = carry;
    }
}
