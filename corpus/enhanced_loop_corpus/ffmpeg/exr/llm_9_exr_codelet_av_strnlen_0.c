#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by skipping every other element, but perform more operations per iteration
    for (i = 0; i < len && s[i]; i += 2) {
        // Introduce additional memory access and arithmetic to maintain work per iteration
        if (i + 1 < len) {
            volatile uint8_t combined = s[i] ^ s[i + 1];
            (void)combined;
        }
        // Extra computation to balance reduced iterations
        for (size_t j = 0; j < 2; j++) {
            volatile size_t touch = (i + j) & 0xFF;
            (void)touch;
        }
    }
    // Ensure i is within bounds after loop in case of skip-over
    if (i > len) i = len;
}
