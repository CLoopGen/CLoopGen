#include <stdio.h>

#include <inttypes.h>

extern unsigned char *buffer;
extern int wd_size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < wd_size; i++) {
        if (i % 2 == 0) {
            continue;
        }
        buffer[i] = 0;
    }
}
