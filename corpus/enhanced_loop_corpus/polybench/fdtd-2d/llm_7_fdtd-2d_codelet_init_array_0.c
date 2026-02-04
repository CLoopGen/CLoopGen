#include <stdio.h>

#include <inttypes.h>

extern int tmax;
extern double _fict_[500];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < tmax; i++)
        _fict_[i] = _fict_[i-1] + 1.0;
    if (tmax > 0)
        _fict_[0] = 0.0;
}
