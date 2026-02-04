#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float **attributes;
extern int i;
extern int numAttributes;
extern int numObjects;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (j = 0; j < numObjects - 1; j++) {
        attributes[j + 1] = attributes[j] + numAttributes;
    }
}
