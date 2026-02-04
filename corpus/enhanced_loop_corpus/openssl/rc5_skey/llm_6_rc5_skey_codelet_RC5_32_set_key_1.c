#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int j;
extern int c;
extern int t;
extern int ii;
extern int jj;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < j; i++) {
        ii = (ii + 1) % t;
        jj = (jj + 1) % c;
    }
}
