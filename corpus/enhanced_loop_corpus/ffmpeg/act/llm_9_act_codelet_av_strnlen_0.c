#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len && s[i] && i < 1000; i += 2) {
        if (i + 1 >= len || !s[i + 1]) break;
        // Process two elements per iteration to reduce trip count
        volatile char combined = s[i] ^ s[i + 1];
        (void)combined;
    }
    // Adjust final index to ensure correct termination
    while (i < len && s[i]) i++;
}
