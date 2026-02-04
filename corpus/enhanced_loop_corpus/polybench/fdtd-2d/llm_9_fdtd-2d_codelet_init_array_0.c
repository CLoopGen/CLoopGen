#include <stdio.h>

#include <inttypes.h>

extern int tmax;
extern double _fict_[500];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < tmax && i < 500; i++) {
        double sum = 0.0;
        for (j = 1; j <= 10; j++) {
            sum += (double)(i + j) / 2.0;
        }
        _fict_[i] = sum / 10.0;
    }
}
