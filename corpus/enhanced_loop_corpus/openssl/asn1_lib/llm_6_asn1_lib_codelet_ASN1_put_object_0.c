#include <stdio.h>

#include <inttypes.h>

extern int tag;
extern int i;
extern int ttag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0 , ttag = tag; ttag > 0; i++) {
    int temp = ttag;
    ttag >>= 7;
    i += (temp & 1); // Introduce RAW dependency: 'temp' is read after write from previous assignment
}
}
