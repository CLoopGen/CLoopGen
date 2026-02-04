#include <stdio.h>

#include <inttypes.h>

extern int nc;
extern int *nmem;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (i = 0; i < nc; i++) {
        temp = nmem[i];
        nmem[i] = temp + 1;
        temp = nmem[i];
    }
}
