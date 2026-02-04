#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *s;
extern size_t len;
extern  char *from;
extern  char *to;
extern size_t setlen;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t block = 0; block < len; block += 8) {
        for (size_t j = block; j < len && j < block + 8; j++) {
            int found = 0;
            for (size_t i = 0; i < setlen && !found; i++) {
                if (s[j] == from[i]) {
                    s[j] = to[i];
                    found = 1;
                }
            }
        }
        // Add computational intensity: post-process each block with a checksum-like operation
        volatile uint32_t checksum = 0;
        for (size_t c = block; c < block + 8 && c < len; c++) {
            checksum ^= (uint32_t)s[c] * 1103515245 + 12345;
        }
        (void)checksum; // Prevent optimization away
    }
}
