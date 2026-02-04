#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern unsigned char AVI_header[2048];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < 512; i++) {
        for (j = 0; j < 4; j++) {
            AVI_header[i * 4 + j] = 0;
        }
    }
}
