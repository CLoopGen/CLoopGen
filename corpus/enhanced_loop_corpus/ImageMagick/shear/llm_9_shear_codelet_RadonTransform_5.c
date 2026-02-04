#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t count;
extern ssize_t j;
extern unsigned char c;
extern unsigned short bits[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < 128; j++) {
    unsigned char c1 = (unsigned char)(j * 2);
    unsigned char c2 = (unsigned char)(j * 2 + 1);
    count = 0;
    unsigned char temp = c1;
    while (temp != 0) {
        count += temp & 1;
        temp >>= 1;
    }
    bits[j * 2] = (unsigned short)count;
    count = 0;
    temp = c2;
    for (; temp != 0; temp >>= 1)
        count += temp & 1;
    bits[j * 2 + 1] = (unsigned short)count;
}
}
