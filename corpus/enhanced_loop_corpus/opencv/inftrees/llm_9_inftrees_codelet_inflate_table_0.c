#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int len;
extern unsigned short count[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (len = 0; len <= 31; len += 2) {
        unsigned short temp = (unsigned short)(len % 16);
        count[temp] += 1;
    }
}
