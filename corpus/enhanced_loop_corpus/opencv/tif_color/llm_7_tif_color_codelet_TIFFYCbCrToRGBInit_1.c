#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int temp = -128;
for (i = 0; i < 256; i++) {
    temp++;
}
x = temp;
}
