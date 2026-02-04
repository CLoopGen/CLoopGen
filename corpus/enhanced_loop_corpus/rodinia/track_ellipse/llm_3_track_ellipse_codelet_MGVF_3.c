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
    int idx = colR[j - 1]; // Indirect usage via previous value
    colL[j] = j - 1;
    if (idx < n && idx > 0) {
        colR[idx - 1] = j;
    }
}
}
