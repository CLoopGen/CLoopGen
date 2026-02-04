#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive two-step access with temporary aggregation
    for (i = 0; i < len - 1; i += 2) {
        if (!s[i] || !s[i+1]) break;
    }
    // Handle odd-length or boundary case
    if (i == len - 1 && s[i]) i++;
}
