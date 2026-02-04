#include <stdio.h>

#include <inttypes.h>

extern unsigned char *cookie;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int temp = 0;
    for (i = 0; i < 20; i++) {
        temp = i + 1;
        *cookie = temp;
        cookie++;
    }
}
