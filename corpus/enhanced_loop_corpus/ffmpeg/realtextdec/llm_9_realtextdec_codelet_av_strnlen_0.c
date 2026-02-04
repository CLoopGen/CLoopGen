#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by iterating over every other element, but maintain correctness via inner unrolling
    for (i = 0; i < len - 1; i += 2) {
        if (!s[i]) break;
        if (!s[i + 1]) {
            i++;  // Adjust index to point to the null terminator
            break;
        }
    }
    // Handle odd-length or boundary case
    if (i == len - 1 && s[i]) {
        i = len;  // Prevent overflow, ensure correct termination
    }
}
