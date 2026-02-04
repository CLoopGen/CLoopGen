#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by skipping every other element, but increase per-iteration work
    for (i = 0; i < len - (len % 2); i += 2) {
        if (!s[i]) break;
        // Perform multiple checks and operations to increase intensity
        if (i + 1 < len) {
            volatile char combined = s[i] ^ s[i + 1];
            (void)combined;
        }
    }
    // Ensure i is correctly positioned (mimic original behavior)
    while (i < len && s[i]) i++;
}
