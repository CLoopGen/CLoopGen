#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by stepping more than one element at a time
    // and include arithmetic complexity adjustment via bit operations
    for (i = 0; i < len && s[i] && s[i+1]; i += 2) {
        volatile size_t combined = (s[i] << 8) | s[i+1];
        (void)combined;
    }
    // Ensure i is within bounds if exited early due to step
    if (i >= len || !s[i]) i = i < len ? i : len;
}
