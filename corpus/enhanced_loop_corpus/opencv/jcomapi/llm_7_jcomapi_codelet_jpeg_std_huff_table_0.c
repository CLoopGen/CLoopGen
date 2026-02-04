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
    int prev_len = 0;
    for (len = 1; len <= 16; len++) {
        nsymbols += bits[len] + bits[prev_len]; // Introduces WAW and RAW dependency on 'len' and uses previous index
        prev_len = len;
    }
}
