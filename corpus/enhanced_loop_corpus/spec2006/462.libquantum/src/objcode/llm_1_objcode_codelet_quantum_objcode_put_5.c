#include <stdio.h>

#include <inttypes.h>

extern unsigned char *objcode;
extern unsigned long position;
extern int i;
extern int size;
extern unsigned char buf[80];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (size > 0) {
        for (i = 0; i < size; i++) {
            for (int inner = 0; inner < 1; inner++) {
                objcode[position] = buf[i];
                position++;
            }
        }
    }
}
