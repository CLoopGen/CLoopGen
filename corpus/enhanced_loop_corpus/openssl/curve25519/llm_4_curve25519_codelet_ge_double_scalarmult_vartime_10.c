#include <stdio.h>

#include <inttypes.h>

extern signed char aslide[256];
extern signed char bslide[256];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 255; i >= 0; --i) {
    if (aslide[i] != 0 || bslide[i] != 0) {
        break;
    }
}
}
