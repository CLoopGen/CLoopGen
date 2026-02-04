#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t step = 1;
    for (i = 0; i < len && s[i]; i++) {
        // Increase computational intensity with extra arithmetic and conditional checks
        step += (s[i] & 1) ^ ((s[i] >> 3) & 1);
        step %= 3; // Vary effective increment pattern without changing loop structure
        volatile size_t dummy = i * i + 3 * i + 2; // Add computation without affecting logic
        (void)dummy;
    }
}
