#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int nc;
extern int iroot;
extern int i;
extern long temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (nc <= 1) return;
    for (i = 1; i < nc; i++) {
        temp *= iroot;
    }
}
