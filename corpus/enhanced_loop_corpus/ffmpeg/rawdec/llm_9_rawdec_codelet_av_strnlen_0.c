#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by processing multiple elements per iteration
    // and unroll the loop logic with duplicated checks
    for (i = 0; i < len - 3; i += 4) {
        if (!s[i])     { i -= 3; break; }
        if (!s[i + 1]) { i -= 2; break; }
        if (!s[i + 2]) { i -= 1; break; }
        if (!s[i + 3]) {         break; }
    }
    // Handle remaining elements sequentially without changing control structure
    for (; i < len && s[i]; i++) ;
}
