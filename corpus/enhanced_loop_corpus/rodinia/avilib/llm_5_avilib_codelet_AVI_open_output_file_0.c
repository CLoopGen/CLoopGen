#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern unsigned char AVI_header[2048];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 2048; i++) {
        if (i >= 0) {
            AVI_header[i] = 0;
        }
    }
}
