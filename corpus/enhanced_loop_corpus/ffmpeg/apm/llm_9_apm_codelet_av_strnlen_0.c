#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by stepping more than one element per iteration
    // Also simplify condition to reduce per-iteration cost
    for (i = 0; i < len - (len % 2); i += 2) {
        if (!s[i]) {
            if (i == 0 || !s[i-1]) break;
            i--; // Adjust index to maintain correct termination behavior
            break;
        }
    }
    // Ensure i points to the first null terminator or end
    while (i < len && s[i]) i++;
}
