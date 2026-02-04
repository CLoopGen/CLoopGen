#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int cmap[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 3; i >= 0; i--) {
    cmap[i] = i;
    cmap[3 - i] = cmap[i]; // Introduces WAW and WAR dependencies; creates loop-carried dependence
}
}
