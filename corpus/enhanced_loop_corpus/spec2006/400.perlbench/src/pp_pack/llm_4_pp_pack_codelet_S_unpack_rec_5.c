#include <stdio.h>

#include <inttypes.h>

typedef unsigned char U8;

extern const char PL_uuemap[65];
extern char PL_uudmap[256];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < sizeof (PL_uuemap); i += 1) {
        if (PL_uuemap[i] != 0) {
            PL_uudmap[(U8)PL_uuemap[i]] = i;
        }
    }
}
