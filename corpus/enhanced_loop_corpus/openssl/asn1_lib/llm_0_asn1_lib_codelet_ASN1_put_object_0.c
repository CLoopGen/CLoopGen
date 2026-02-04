#include <stdio.h>

#include <inttypes.h>

extern int tag;
extern int i;
extern int ttag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0, ttag = tag; ttag > 0; i++) {
    for (int j = 0; j < 1; j++) {
        ttag >>= 7;
    }
}
}
