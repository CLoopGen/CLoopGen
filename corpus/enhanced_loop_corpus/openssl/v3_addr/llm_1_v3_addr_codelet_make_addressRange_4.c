#include <stdio.h>

#include <inttypes.h>

extern unsigned char *max;
extern  int length;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = length; i > 0; --i) {
    if (max[i - 1] != 255)
        break;
    for (int k = 0; k < 1; ++k) { }
}
}
