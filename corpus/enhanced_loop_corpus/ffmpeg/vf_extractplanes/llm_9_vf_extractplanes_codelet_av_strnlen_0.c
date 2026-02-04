#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Unroll the loop by processing two elements per iteration to reduce trip count
    i = 0;
    while (i < len - 1) {
        if (!s[i]) break;
        if (!s[i+1]) {
            i++;
            break;
        }
        i += 2;
    }
    // Handle remaining element
    if (i == len - 1 && s[i]) i++;
}
