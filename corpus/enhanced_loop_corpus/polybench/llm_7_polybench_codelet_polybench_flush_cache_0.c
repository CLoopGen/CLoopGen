#include <stdio.h>

#include <inttypes.h>

extern int cs;
extern double *flush;
extern int i;
extern double tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double prev = 0.0;
    for (i = 0; i < cs; i++) {
        double current = flush[i] + prev;
        tmp += current;
        prev = current;
    }
}
