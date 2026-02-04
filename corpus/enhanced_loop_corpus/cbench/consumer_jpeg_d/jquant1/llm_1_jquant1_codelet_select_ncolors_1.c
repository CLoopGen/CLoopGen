#include <stdio.h>

#include <inttypes.h>

extern int nc;
extern int iroot;
extern int i;
extern long temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < nc; i++) {
        for (int k = 0; k < 1; k++)
            temp *= iroot;
    }
}
