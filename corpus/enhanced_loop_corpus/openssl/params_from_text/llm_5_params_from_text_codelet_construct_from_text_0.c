#include <stdio.h>

#include <inttypes.h>

extern void *buf;
extern unsigned char *cp;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (cp = buf; i-- > 0; )
        if (*cp != 0)
            *cp ^= 255;
        else
            cp++;
}
