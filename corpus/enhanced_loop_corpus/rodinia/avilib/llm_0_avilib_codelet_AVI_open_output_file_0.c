#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern unsigned char AVI_header[2048];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 2048; j += 16) {
        for (i = j; i < j + 16 && i < 2048; i++)
            AVI_header[i] = 0;
    }
}
