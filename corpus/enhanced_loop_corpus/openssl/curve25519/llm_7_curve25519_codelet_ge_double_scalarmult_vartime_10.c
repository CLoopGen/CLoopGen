#include <stdio.h>

#include <inttypes.h>

extern signed char aslide[256];
extern signed char bslide[256];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    int found = 0;
    for (j = 255; j >= 0 && !found; --j) {
        aslide[j] = aslide[j]; // WAW dependency on aslide[j] (redundant write, preserves semantics)
        if (aslide[j] || bslide[j]) {
            i = j;
            found = 1;
        }
        bslide[j] = bslide[j]; // WAW dependency on bslide[j]
    }
    if (!found) {
        i = -1;
    }
}
