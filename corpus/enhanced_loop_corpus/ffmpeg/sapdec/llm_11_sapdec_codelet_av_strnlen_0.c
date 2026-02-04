#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by iterating over every fourth element, then adjust final position
    for (i = 0; i + 3 < len && s[i]; i += 4) {
        if (!s[i + 1]) { i += 1; break; }
        if (!s[i + 2]) { i += 2; break; }
        if (!s[i + 3]) { i += 3; break; }
    }
    // Finalize index to point to the first null or end
    while (i < len && s[i]) i++;
}
