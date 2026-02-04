#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by incrementing in larger steps, but maintain correctness via bounds check
    // Also unroll the loop partially to change execution pattern
    for (i = 0; i < len; i += 4) {
        if (s[i]) {
            if (i + 1 < len && !s[i + 1]) { i++; break; }
            if (i + 2 < len && !s[i + 2]) { i += 2; break; }
            if (i + 3 < len && !s[i + 3]) { i += 3; break; }
        } else {
            break;
        }
    }
    // Ensure i points to the correct termination index
    for (; i < len && s[i]; i++)
        ;
}
