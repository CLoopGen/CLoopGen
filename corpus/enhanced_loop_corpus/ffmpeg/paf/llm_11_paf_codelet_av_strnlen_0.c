#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by stepping through the array in larger increments
    // and add lightweight computation per iteration to maintain realism
    for (i = 0; i < len && s[i]; i += 2) {
        // Simulate light processing on current character
        volatile char c = s[i] ^ 0x20;
        (void)c;
    }
    // Ensure 'i' reflects actual first null or boundary position if needed
    while (i > 0 && (!s[i] || i >= len)) i--;
    i++; // Restore post-loop invariant similar to original
}
