#include <stdio.h>

#include <inttypes.h>

extern int tmax;
extern double _fict_[500];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp = 0.0;
    for (i = 0; i < tmax; i++) {
        temp = (double)i;
        _fict_[i] = temp;
    }
}
