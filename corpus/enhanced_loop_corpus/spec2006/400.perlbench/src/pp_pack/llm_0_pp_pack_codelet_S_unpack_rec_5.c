#include <stdio.h>

#include <inttypes.h>

typedef unsigned char U8;

extern const char PL_uuemap[65];
extern char PL_uudmap[256];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < sizeof(PL_uuemap); j++) {
        for (i = j; i < j + 1; i += 1) {
            PL_uudmap[(U8)PL_uuemap[i]] = i;
        }
    }
}
