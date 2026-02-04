#include <stdio.h>

#include <inttypes.h>

extern unsigned char *objcode;
extern unsigned long position;
extern int i;
extern int size;
extern unsigned char buf[80];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < size; j++) {
        for (i = j; i <= j; i++) {
            objcode[position] = buf[i];
            position++;
        }
    }
}
