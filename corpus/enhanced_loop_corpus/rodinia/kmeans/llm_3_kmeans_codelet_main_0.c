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
    // Variant 2: Reverse consecutive memory access – process array from end to beginning
    int j;
    for (j = numObjects - 1; j >= 1; j--) {
        attributes[j] = attributes[j - 1] + numAttributes;
    }
}
