#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *key;
extern int keylen;
extern int s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (s = 0; s < keylen; s += 2) {
        if (key[s] == '{')
            break;
    }
    // Adjust s to point to the actual found index if broken on even index
    // If loop exits due to break and s is beyond valid range, correct it
    if (s >= keylen && key[s - (s % 2)] == '{') 
        s = s - (s % 2);
}
