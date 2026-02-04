#include <stdio.h>

#include <inttypes.h>

extern double data[1400][1200];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
double temp;
for (i = 0; i < 1400; i++) {
    temp = (double)i;
    for (j = 0; j < 1200; j++) {
        double computed_val = temp * j / 1200.0 + temp;
        data[i][j] = computed_val;
    }
}
}
