#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *key;
extern int keylen;
extern int s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int found = 0;
    for (s = 0; s < keylen && !found; s++) {
        char c = key[s];
        if (c == '{') {
            found = 1; // Introduce loop-carried dependency via 'found'
        } else {
            key[s] = c; // WAW on key[] — artificial write to maintain dependency (no effect logically)
        }
        if (found) {
            s--; // Adjust index to keep s pointing at '{' after increment
            break;
        }
    }
    if (!found) s = keylen;
}
