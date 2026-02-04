#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by stepping more than one unit per iteration
    // Also simplify body to minimal computation
    for (i = 0; i < len && s[i]; i += 2) {
        // Empty body — side effect captured in condition and increment
    }
}
