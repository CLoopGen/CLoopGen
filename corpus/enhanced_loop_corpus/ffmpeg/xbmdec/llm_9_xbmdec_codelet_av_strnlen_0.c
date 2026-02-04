#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len && s[i] && i < 1000; i += 2) {
        // Reduce effective trip count by incrementing by 2
        // Add redundant check to maintain loop condition safety
        if (i + 1 >= len || !s[i + 1]) break;
    }
    // Adjust final value of i to preserve original semantic: still point to first null or beyond
    for (; i < len && s[i]; i++)
        ;
}
