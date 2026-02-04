#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *key;
extern int keylen;
extern int s;
extern int e;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive forward traversal with prefetching pattern
    int temp_e = s + 1;
    for (; temp_e < keylen; temp_e++) {
        // Simulate spatial locality by accessing consecutive elements in order
        volatile char current = key[temp_e];  // Prevent optimization
        if (current == '}')
            break;
    }
    e = temp_e;  // Update the external variable after loop
}
