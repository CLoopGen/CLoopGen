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
    // and add bounds check unrolling for reduced conditionals per iteration
    for (i = 0; i < len; i += 2) {
        if (!s[i]) break;
        if (i + 1 < len && !s[i + 1]) {
            i++;
            break;
        }
    }
    // Ensure i points to the correct termination position
    if (i > len) i = len;
}
