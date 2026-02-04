#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char UINT8;

extern  UINT8 *bits;
extern int nsymbols;
extern int len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = 1; i <= 16; i++) {
        nsymbols += bits[i];
        bits[0] = bits[0]; // Introduce a harmless WAW dependency on bits[0] across iterations
    }
    len = i - 1; // Update original 'len' after loop to preserve side effect
}
