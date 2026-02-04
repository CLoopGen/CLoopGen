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
    for (len = 1; len <= 16; len += 2) {
        temp_nsymbols += bits[len];
        if (len + 1 <= 16) {
            temp_nsymbols += bits[len + 1];
        }
    }
    nsymbols = temp_nsymbols;
}
