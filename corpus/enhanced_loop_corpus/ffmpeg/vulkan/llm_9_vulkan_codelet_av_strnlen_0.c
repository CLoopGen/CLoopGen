#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by looping over even indices only, then check adjacent
    for (i = 0; i < len - 1 && s[i] && s[i+1]; i += 2) {
        // Perform dual checks per iteration, effectively halving the trip count
        if (!s[i]) break;
        if (!s[i+1]) { i++; break; }
    }
    // Handle case where loop ended prematurely and last char needs checking
    if (i == len - 1 && s[i]) i++;
}
