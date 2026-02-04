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
    int temp_nsymbols = nsymbols;
    for (int len = 1; len <= 16; len++) {
        temp_nsymbols += bits[len];
    }
    nsymbols = temp_nsymbols;
}
