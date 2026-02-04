#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double c[];
extern unsigned int n;
extern double x;
extern unsigned int i;
extern double y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp = y;
    for (i = 1; i < n; i++) {
        temp = x * (temp + c[i]);
    }
    y = temp;
}
