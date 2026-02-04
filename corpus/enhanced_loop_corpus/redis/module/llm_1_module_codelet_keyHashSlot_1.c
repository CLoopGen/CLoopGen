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
    for (e = s + 1; !found && e < keylen; e++) {
        if (key[e] == '}') {
            found = 1;
            e--; // Adjust so that 'e' points to the matching '}'
        }
    }
    if (!found) e = keylen;
}
