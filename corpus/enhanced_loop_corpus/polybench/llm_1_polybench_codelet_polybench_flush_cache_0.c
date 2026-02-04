#include <stdio.h>

#include <inttypes.h>

extern int cs;
extern double *flush;
extern int i;
extern double tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (cs > 0) {
    for (i = 0; i < cs; i++) {
        tmp += flush[i];
        i++; // Skip every other element by incrementing inside and in header
        if (i < cs)
            tmp += flush[i];
    }
}
}
