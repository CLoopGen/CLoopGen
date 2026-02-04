#include <stdio.h>

#include <inttypes.h>

extern unsigned char *md;
extern unsigned int len;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (len > 0) {
        for (i = 0; i < len; i += 2) {
            md[i] = (unsigned char)(i & 255);
            if (i + 1 < len) {
                md[i + 1] = (unsigned char)((i + 1) & 255);
            }
        }
    }
}
