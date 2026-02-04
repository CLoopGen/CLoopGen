#include <stdio.h>

#include <inttypes.h>

extern int cs;
extern double *flush;
extern int i;
extern double tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < cs * 3; i += 3) {
        tmp += flush[i % cs];
        if (i + 1 < cs) tmp += flush[(i + 1) % cs];
        if (i + 2 < cs) tmp += flush[(i + 2) % cs];
    }
}
