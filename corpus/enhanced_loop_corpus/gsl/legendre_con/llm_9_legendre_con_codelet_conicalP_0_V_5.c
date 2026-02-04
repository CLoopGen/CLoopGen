#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double tau;
extern double V[12];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
double temp[12];
temp[0] = V[0];
for (i = 1; i <= 11; i++) {
    temp[i] = temp[i - 1] * tau;
}
for (i = 0; i <= 11; i++) {
    V[i] = temp[i];
}
}
