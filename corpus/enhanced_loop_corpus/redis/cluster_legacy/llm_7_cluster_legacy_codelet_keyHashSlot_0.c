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
        found = (key[s] == '{');
        if (found) {
            s--; // Adjust so that `s` points to the position of '{'
        }
    }
    if (!found) {
        s = keylen;
    } else {
        s++; // Compensate for the decrement and ensure correct final value
    }
}
