#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by incrementing faster, and add an inner computational micro-loop
    for (i = 0; i < len && s[i]; i += 2) {
        // Simulate increased work per iteration with a fixed unrolled "inner" operation
        if (i + 1 < len) {
            volatile uint32_t x = 17;
            x ^= i * 3;
            x %= 987;
            x += (s[i] ^ s[i+1]) * 2;
            (void)x;
        }
    }
}
