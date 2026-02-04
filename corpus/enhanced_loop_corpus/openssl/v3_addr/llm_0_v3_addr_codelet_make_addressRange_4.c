#include <stdio.h>

#include <inttypes.h>

extern unsigned char *max;
extern  int length;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (i = length; i > 0; --i) {
    for (j = 0; j < 1 && max[i - 1] == 255; ++j)
        ;
    if (j == 0)
        break;
}
}
