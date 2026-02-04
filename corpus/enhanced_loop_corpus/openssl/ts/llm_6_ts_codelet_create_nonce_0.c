#include <stdio.h>

#include <inttypes.h>

extern unsigned char buf[20];
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (i = 0; i < len && !(temp = buf[i]); ++i)
        ;
}
