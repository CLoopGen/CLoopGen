#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *b1;
extern  uint8_t *b2;
extern int a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (a = 0; a < 3; a++) {
    // Changed to consecutive memory access pattern using array indexing from base pointers
    const uint8_t *base1 = b1;
    const uint8_t *base2 = b2;
    size_t offset = a; // Use index to access consecutive positions

    const uint8_t *block1 = base1 + offset;
    const uint8_t *block2 = base2 + offset;

    // Emulate original control flow effect with data usage instead of pointer skips
    switch (a) {
      case 0:
        block1++;
        block2++;
        break;
      case 1:
        block2++;
        break;
      case 2:
        // Access remains consecutive; no extra increment
        break;
    }
    // Ensure pointers are used (e.g., dummy load to prevent optimization)
    (void)block1;
    (void)block2;
}
}
