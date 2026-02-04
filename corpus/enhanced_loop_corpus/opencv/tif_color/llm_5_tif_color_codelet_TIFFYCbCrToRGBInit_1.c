#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0 , x = -128; i < 256 && x < 0; i++ , x++) {
    if (i >= 128) {
        break;
    }
}
}
