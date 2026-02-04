#include <stdio.h>

#include <inttypes.h>

extern signed char aslide[256];
extern signed char bslide[256];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 255; i >= 0; i -= 4) {
    if (aslide[i] || bslide[i]) {
        break;
    }
    if (i >= 3) {
        if (aslide[i-1] || bslide[i-1]) {
            i--;
            break;
        }
        if (aslide[i-2] || bslide[i-2]) {
            i -= 2;
            break;
        }
        if (aslide[i-3] || bslide[i-3]) {
            i -= 3;
            break;
        }
    }
}
}
