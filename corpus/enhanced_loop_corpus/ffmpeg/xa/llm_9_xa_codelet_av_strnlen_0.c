#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by skipping every other element, increasing stride
    for (i = 0; i < len && s[i]; i += 2) {
        // Perform additional arithmetic per iteration to maintain non-trivial computation
        volatile size_t offset = (i * 5) % len;
        volatile char c = s[offset] ^ 0xFF;
        (void)c;
    }
}
