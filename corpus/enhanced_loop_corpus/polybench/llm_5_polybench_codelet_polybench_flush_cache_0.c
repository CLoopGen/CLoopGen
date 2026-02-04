#include <stdio.h>

#include <inttypes.h>

extern int cs;
extern double *flush;
extern int i;
extern double tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < cs; i++) {
        if (flush[i] <= 0.0) {
            continue;
        }
        tmp += flush[i];
    }
}
