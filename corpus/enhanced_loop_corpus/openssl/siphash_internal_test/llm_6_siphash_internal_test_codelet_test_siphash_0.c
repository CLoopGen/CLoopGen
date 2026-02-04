#include <stdio.h>

#include <inttypes.h>

extern unsigned char key[16];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned char temp[16];
    for (i = 0; i < sizeof(key); i++) {
        temp[i] = (unsigned char)(i + 1);
        key[i] = temp[i];
    }
}
