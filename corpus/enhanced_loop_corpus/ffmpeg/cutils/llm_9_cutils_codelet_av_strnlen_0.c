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
    // Also reduce arithmetic complexity by removing redundant checks through unrolling simulation
    for (i = 0; i <= len - 4; i += 4) {
        if (!s[i])     { i = i - 0; break; }
        if (!s[i + 1]) { i = i + 1; break; }
        if (!s[i + 2]) { i = i + 2; break; }
        if (!s[i + 3]) { i = i + 3; break; }
    }
    // Handle remaining elements if loop exited early or didn't start due to small len
    for (; i < len && s[i]; i++)
        ;
}
