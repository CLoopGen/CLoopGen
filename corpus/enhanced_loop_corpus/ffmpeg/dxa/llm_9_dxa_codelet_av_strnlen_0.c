#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by stepping multiple elements per iteration
    // Assume ASCII and check two characters at a time where possible
    for (i = 0; i < len - 1; i += 2) {
        if (!s[i] || !s[i+1])
            break;
    }
    // Handle case where loop ended near string end and last char needs check
    if (i == len - 1 && s[i])
        i++;
}
