#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern unsigned char AVI_header[2048];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 512; i++) {
        AVI_header[i * 4 + 0] = 0;
        AVI_header[i * 4 + 1] = 0;
        AVI_header[i * 4 + 2] = 0;
        AVI_header[i * 4 + 3] = 0;
    }
}
