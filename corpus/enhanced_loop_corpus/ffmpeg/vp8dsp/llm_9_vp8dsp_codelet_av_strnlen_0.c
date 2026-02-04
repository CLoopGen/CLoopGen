#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len && s[i] && s[i+1] && s[i+2]; i += 3) {
        // Process multiple elements per iteration, reducing trip count
        // Advance by 3 under the assumption of sufficient buffer length
        if (i + 2 >= len) break;
    }
    // Adjust final position if needed
    while (i < len && s[i]) i++;
    if (i > len) i = len;
}
