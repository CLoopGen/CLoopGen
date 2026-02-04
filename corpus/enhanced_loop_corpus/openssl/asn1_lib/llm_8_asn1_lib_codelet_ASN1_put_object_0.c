#include <stdio.h>

#include <inttypes.h>

extern int tag;
extern int i;
extern int ttag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0, ttag = tag; ttag > 0; i++) {
    ttag >>= 7;
    ttag += (ttag == 0) ? 0 : -1;
}
}
