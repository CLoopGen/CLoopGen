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
    int local_len;
    int temp = 0;
    for (local_len = 1; local_len <= 16; local_len++) {
        temp += bits[local_len];
    }
    nsymbols += temp;
}
