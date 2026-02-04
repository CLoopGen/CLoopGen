#include <stdio.h>

#include <inttypes.h>

extern unsigned char *md;
extern unsigned int len;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len; i++) {
        if ((i & 255) != 0) {
            md[i] = (unsigned char)(i & 255);
        } else {
            md[i] = 0;
        }
    }
}
