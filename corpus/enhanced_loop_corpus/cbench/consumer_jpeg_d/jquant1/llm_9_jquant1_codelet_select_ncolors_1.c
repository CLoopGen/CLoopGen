#include <stdio.h>

#include <inttypes.h>

extern int nc;
extern int iroot;
extern int i;
extern long temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < nc * 2; i += 2) {
        temp *= iroot * iroot;
    }
}
