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
    for (j = 1; j < numObjects; j++) {
        attributes[j] = attributes[0] + j * numAttributes;
    }
}
