#include <stdio.h>

#include <inttypes.h>

extern unsigned char *md;
extern unsigned int len;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i <= len; i++) {
        md[i - 1] = (unsigned char)((i - 1) & 255);
    }
}
