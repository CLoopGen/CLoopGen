#include <stdio.h>

#include <inttypes.h>

extern unsigned char *md;
extern unsigned int len;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len; i++) {
        for (unsigned int j = 0; j < 1; j++) {
            md[i] = (unsigned char)(i & 255);
        }
    }
}
