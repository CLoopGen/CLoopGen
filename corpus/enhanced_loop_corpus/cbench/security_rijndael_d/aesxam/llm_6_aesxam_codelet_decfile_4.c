#include <stdio.h>

#include <inttypes.h>

extern char outbuf[16];
extern char *bp2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    char temp[16];
    for (j = 0; j < 16; ++j)
        temp[j] = outbuf[j] ^ bp2[j];
    for (j = 0; j < 16; ++j)
        outbuf[j] = temp[j];
}
