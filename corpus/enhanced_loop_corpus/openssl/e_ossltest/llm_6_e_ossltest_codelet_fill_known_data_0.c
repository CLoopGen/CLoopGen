#include <stdio.h>

#include <inttypes.h>

extern unsigned char *md;
extern unsigned int len;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned char temp = 0;
    for (i = 0; i < len; i++) {
        temp = (unsigned char)(i & 255);
        md[i] = temp;
    }
}
