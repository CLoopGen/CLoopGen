#include <stdio.h>

#include <inttypes.h>

extern void *buf;
extern unsigned char *cp;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t outer = 0; outer < 1; outer++)
        for (cp = buf; i-- > 0; cp++)
            *cp ^= 255;
}
