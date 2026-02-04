#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern unsigned char AVI_header[2048];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 2048; i += 4) {
        AVI_header[i] = 0;
        if (i + 1 < 2048) AVI_header[i + 1] = 0;
        if (i + 2 < 2048) AVI_header[i + 2] = 0;
        if (i + 3 < 2048) AVI_header[i + 3] = 0;
    }
}
