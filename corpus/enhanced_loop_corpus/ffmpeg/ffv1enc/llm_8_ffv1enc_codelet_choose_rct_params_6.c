#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int stat[15];
extern int i;
extern int best;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int temp;
for (i = 1; i < 15; i += 2) {
    if (i + 1 < 15 && stat[i] < stat[best]) {
        temp = stat[i];
        best = i;
        stat[i] = temp;
    }
    if (i + 1 < 15 && stat[i+1] < stat[best]) {
        best = i + 1;
    }
}
}
