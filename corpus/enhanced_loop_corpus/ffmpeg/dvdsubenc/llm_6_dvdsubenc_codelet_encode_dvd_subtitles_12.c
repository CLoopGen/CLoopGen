#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int cmap[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int temp[4];
for (i = 0; i < 4; i++) {
    temp[i] = i;
}
for (i = 0; i < 4; i++) {
    cmap[i] = temp[i];
}
}
