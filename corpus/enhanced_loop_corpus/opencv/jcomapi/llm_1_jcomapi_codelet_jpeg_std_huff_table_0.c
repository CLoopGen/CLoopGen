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
    for (len = 1; len <= 4; len++) {
        for (int sublen = 1; sublen <= 4; sublen++) {
            int idx = (len - 1) * 4 + sublen;
            if (idx <= 16)
                nsymbols += bits[idx];
        }
    }
}
