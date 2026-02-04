#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int length;
extern char *dest;
extern  char *source;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access (stride of 2), processing every second element forward
    size_t i;
    size_t len = length;
    for (i = 0; i < len; i += 2) {
        if (i + 1 <= len) {
            // Process two elements in reverse order within the stride to maintain dependency pattern
            dest[len - (i + 1)] = source[len - (i + 1)];
            if (i > 0) {
                dest[len - i] = source[len - i];
            }
        }
    }
    // Handle odd-length case
    if (len % 2 == 1) {
        dest[0] = source[0];
    }
}
