#include <stdio.h>

#include <inttypes.h>

extern unsigned char *buffer;
extern int wd_size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (j = 0; j < wd_size; j += 2) {
        if (j + 1 < wd_size) {
            buffer[j]     = 0;
            buffer[j + 1] = 0;
        } else {
            buffer[j] = 0;
        }
    }
}
