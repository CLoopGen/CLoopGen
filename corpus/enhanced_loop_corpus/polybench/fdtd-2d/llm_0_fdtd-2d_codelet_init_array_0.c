#include <stdio.h>

#include <inttypes.h>

extern int tmax;
extern double _fict_[500];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (j = 0; j < tmax; j++) {
    for (i = 0; i <= j; i++)
        _fict_[i] = (double)i;
}
}
