#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int n;
extern int j;
extern int *colL;
extern int *colR;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 2; j < n; j += 2) {
    colL[j] = j - 1;
    colR[j - 1] = j;
    colL[j - 1] = j - 2;
    colR[j - 2] = j - 1;
}
}
