#include <stdio.h>

#include <inttypes.h>

extern unsigned char key[16];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t limit = sizeof(key);
    for (size_t i = 0; i < limit; i++) {
        key[i] = (unsigned char)i;
        i++; 
        if (i < limit) {
            key[i] = (unsigned char)i;
        }
    }
}
