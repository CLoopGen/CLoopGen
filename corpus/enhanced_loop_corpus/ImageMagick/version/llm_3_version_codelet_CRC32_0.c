#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  unsigned char *message;
extern  size_t length;
extern ssize_t i;
extern unsigned int crc_xor[256];
extern unsigned int crc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated via pointer arithmetic)
    // Simulates non-sequential access by accessing message bytes in reverse order
    // This changes access pattern to reverse sequential (still deterministic but different locality)
    ssize_t idx;
    for (i = 0; i < (ssize_t)length; i++) {
        idx = (ssize_t)length - 1 - i;  // Reverse indexing
        crc = crc_xor[(crc ^ message[idx]) & 255] ^ (crc >> 8);
    }
}
