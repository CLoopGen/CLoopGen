#include <stdio.h>

#include <inttypes.h>

extern unsigned char key[16];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    key[0] = 0;
    for (i = 1; i < sizeof(key); i++) {
        key[i] = key[i - 1] + 1;
    }
}
