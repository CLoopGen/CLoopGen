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
    int temp_sum = 0;
    for (len = 1; len <= 8; len++) {
        temp_sum += bits[len] + bits[17 - len];
    }
    nsymbols += temp_sum;
}
