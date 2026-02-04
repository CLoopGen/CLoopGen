#include <stdio.h>

#include <inttypes.h>

extern unsigned char *cookie;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 10; i++, cookie++) {
        unsigned int squared = i * i;
        unsigned int cubed = squared * i;
        *cookie = (unsigned char)(cubed & 0xFF);
    }
}
