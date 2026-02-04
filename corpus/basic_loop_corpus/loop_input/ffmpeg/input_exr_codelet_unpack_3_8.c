#include <stdint.h>
#include <stdlib.h>

uint16_t s[16];
int i;

void init_vars() {
    // Initialize array s with default values
    for (int j = 0; j < 16; j++) {
        s[j] = (uint16_t)(j * 17); // Arbitrary initial pattern
    }
    i = 0; // Initial value before loop use
}