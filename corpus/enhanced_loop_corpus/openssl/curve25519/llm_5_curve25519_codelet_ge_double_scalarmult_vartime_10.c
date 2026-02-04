#include <stdio.h>

#include <inttypes.h>

extern signed char aslide[256];
extern signed char bslide[256];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 255; i >= 0 && !(aslide[i] || bslide[i]); --i) {
    // Empty body: condition moved to loop header
}
}
