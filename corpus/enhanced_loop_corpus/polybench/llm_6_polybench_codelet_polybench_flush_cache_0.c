#include <stdio.h>

#include <inttypes.h>

extern int cs;
extern double *flush;
extern int i;
extern double tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp_local = 0.0;
    for (i = 0; i < cs; i++)
        temp_local += flush[i];
    tmp += temp_local;
}
