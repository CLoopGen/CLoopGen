#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *key;
extern int keylen;
extern int s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (s = 0, i = 1; s < keylen && i; s++) {
        if (key[s] == '{') {
            i = 0;
            s--; // Adjust index to point to the matched '{'
        }
    }
    if (!i) s++; // Restore correct position after decrement
}
