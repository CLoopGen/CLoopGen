#include <stdio.h>

#include <inttypes.h>

extern int tag;
extern int i;
extern int ttag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0, ttag = tag; ttag > 0 && i < 32; i++) {
        if ((ttag & 0x7F) == 0) break;
        ttag >>= 7;
    }
}
