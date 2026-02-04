#include <stdio.h>

#include <inttypes.h>

extern unsigned char *buffer;
extern int wd_size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 4;
    for (i = 0; i < wd_size; i += stride) {
        buffer[i] = 0;
        if (i + 1 < wd_size) buffer[i + 1] = 0;
        if (i + 2 < wd_size) buffer[i + 2] = 0;
        if (i + 3 < wd_size) buffer[i + 3] = 0;
    }
}
