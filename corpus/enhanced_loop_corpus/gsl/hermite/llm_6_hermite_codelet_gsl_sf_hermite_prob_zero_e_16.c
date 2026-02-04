#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int n;
extern double d;
extern double x;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp = d;
    for (j = 1; j < n; j++) {
        temp = j / (x - temp);
    }
    d = temp;
}
