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
for (len = 1; len <= 16; len++) {
    int i;
    for (i = 0; i < len; i++) {
        nsymbols += bits[len];
    }
}
}
