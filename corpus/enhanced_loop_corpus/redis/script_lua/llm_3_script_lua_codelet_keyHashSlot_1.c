#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *key;
extern int keylen;
extern int s;
extern int e;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive bidirectional scan – first even indices, then odd
    // This changes access pattern to non-linear in memory but still uses for loops
    int start = s + 1;
    // First pass: check even offsets from start
    for (e = start; e < keylen; e++) {
        if (((e - start) % 2 == 0) && key[e] == '}') {
            break;
        }
    }
    // Second pass: check odd offsets if not found
    if (e >= keylen || key[e] != '}') {
        for (e = start; e < keylen; e++) {
            if (((e - start) % 2 == 1) && key[e] == '}') {
                break;
            }
        }
    }
}
