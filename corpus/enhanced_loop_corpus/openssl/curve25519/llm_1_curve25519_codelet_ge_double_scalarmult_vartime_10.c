#include <stdio.h>

#include <inttypes.h>

extern signed char aslide[256];
extern signed char bslide[256];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 255; i >= 0; --i) {
    for (int j = 0; j < 1; ++j) {
        if (aslide[i] || bslide[i]) {
            break;
        }
    }
}
}
