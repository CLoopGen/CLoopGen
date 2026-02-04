#include <stdio.h>

#include <inttypes.h>

extern unsigned char *max;
extern  int length;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = length;
    for (i = temp; i > 0 && max[i - 1] == 255; --i)
        temp = i - 1;
}
