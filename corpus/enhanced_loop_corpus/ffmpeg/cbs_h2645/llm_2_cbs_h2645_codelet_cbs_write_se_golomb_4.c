#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int len;
extern uint32_t uvalue;
extern char bits[65];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive memory access by reversing the index order
    // Instead of writing to bits[len + i + 1], we write to bits[i] consecutively
    // The logic is adjusted to store the same bit sequence but in forward order
    uint32_t temp = uvalue + 1;
    for (i = 0; i < len; i++) {
        bits[i] = (temp >> (len - i - 1)) & 1 ? '1' : '0';
    }
}
