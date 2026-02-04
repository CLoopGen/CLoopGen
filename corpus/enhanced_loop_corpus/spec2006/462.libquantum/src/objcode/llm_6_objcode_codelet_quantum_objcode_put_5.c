#include <stdio.h>

#include <inttypes.h>

extern unsigned char *objcode;
extern unsigned long position;
extern int i;
extern int size;
extern unsigned char buf[80];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < size; i++) {
        unsigned long idx = position + i;
        objcode[idx] = buf[i];
    }
    position += size;
}
