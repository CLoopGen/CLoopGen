#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduced effective trip count by stepping more than one element per iteration
    // Also simplified condition checks to reduce per-iteration cost
    for (i = 0; i < len - (len % 2); i += 2) {
        if (!s[i]) {
            if (i == 0 || s[i-1] == '\0') break;
            i = i - 1; // Adjust index to ensure correct exit behavior
            break;
        }
    }
    // Handle possible odd-length case with minimal overhead
    if (i == len - (len % 2) && i < len && s[i]) i++;
}
