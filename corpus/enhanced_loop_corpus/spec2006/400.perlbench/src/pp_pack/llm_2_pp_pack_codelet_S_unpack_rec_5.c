#include <stdio.h>

#include <inttypes.h>

typedef unsigned char U8;

extern const char PL_uuemap[65];
extern char PL_uudmap[256];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int size = sizeof(PL_uuemap);
    for (i = 0; i < size; i += 2) {
        if (i < size) {
            PL_uudmap[(U8)PL_uuemap[i]] = i;
        }
        if (i + 1 < size) {
            PL_uudmap[(U8)PL_uuemap[i + 1]] = i + 1;
        }
    }
}
