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
        // Perform additional arithmetic on each iteration
        size_t j = (i * i + 2 * i + 1) % len; // Example: compute (i+1)^2 mod len
        if (j < len && s[j] == 'a') {
            break;
        }
    }
}
