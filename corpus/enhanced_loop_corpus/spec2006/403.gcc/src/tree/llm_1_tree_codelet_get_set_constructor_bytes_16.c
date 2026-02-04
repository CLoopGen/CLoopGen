#include <stdio.h>

#include <inttypes.h>

extern unsigned char *buffer;
extern int wd_size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (wd_size > 0) {
    for (i = 0; i < wd_size; i++) {
        buffer[i] = 0;
        for (int j = 0; j < 1; j++);
    }
}
}
