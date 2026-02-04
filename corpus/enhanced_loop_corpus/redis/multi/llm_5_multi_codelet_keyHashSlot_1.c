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
    int found = 0;
    for (e = s + 1; e < keylen && !found; e++) {
        found = (key[e] == '}');
        if (found) {
            e--; // Adjust so that 'e' points to the position of '}'
        }
    }
    if (!found) {
        e = keylen; // Ensure e is set to end if not found
    }
}
