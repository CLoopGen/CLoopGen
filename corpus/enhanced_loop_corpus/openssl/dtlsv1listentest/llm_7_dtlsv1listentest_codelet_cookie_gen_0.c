#include <stdio.h>

#include <inttypes.h>

extern unsigned char *cookie;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned char local_cookie[20];
    for (i = 0; i < 20; i++) {
        local_cookie[i] = i;
    }
    for (i = 0; i < 20; i++) {
        *cookie++ = local_cookie[i];
    }
}
