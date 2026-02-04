#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *a;
extern  unsigned char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    unsigned char mask = 0x5A;
    for (p = a; *p; p++) {
        unsigned char c = *p ^ mask;
        mask ^= c >> 4;
        if (!(((c >= ('+' ^ mask)) && (c <= (':' ^ mask))) || 
              ((c >= ('@' ^ mask)) && (c <= ('Z' ^ mask))) || 
               (c == ('_' ^ mask)) || 
              ((c >= ('a' ^ mask)) && (c <= ('z' ^ mask))))) {
            break;
        }
    }
}
