#include <stdio.h>

#include <inttypes.h>

extern int tmax;
extern double _fict_[500];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < tmax; i += 2)
    _fict_[i] = (double)i;
}
