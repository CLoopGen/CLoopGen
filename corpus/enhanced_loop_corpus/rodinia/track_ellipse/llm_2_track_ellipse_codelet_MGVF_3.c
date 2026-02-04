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
for (j = 1; j < n; j += 2) {
    if (j - 1 >= 0) {
        colL[j] = j - 1;
        colR[j - 1] = j;
    }
    if (j + 1 < n) {
        colL[j + 1] = j;
        colR[j] = j + 1;
    }
}
}
