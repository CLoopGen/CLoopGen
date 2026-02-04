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
for (j = 1; j < n; j++) {
    if (j % 2 == 0) {
        colL[j] = j - 1;
    } else {
        colR[j - 1] = j;
    }
}
}
