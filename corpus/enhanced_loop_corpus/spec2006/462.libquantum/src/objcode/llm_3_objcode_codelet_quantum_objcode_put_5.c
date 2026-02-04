#include <stdio.h>

#include <inttypes.h>

extern unsigned char *objcode;
extern unsigned long position;
extern int i;
extern int size;
extern unsigned char buf[80];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse sequential access — copy buffer elements from end to start
    for (i = size - 1; i >= 0; i--) {
        objcode[position] = buf[i];
        position++;
    }
}
