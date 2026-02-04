#include <stdio.h>

#include <inttypes.h>

extern unsigned char *md;
extern unsigned int len;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int j;
    for (i = 0; i < len; i++) {
        for (j = 0; j < 3; j++) {
            md[i] = (unsigned char)((i + j) & 255);
        }
    }
}
