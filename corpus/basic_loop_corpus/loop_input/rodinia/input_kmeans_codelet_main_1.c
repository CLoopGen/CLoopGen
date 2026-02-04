#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float **attributes;
int i;
int numAttributes;
int numObjects;

void init_vars() {
    numAttributes = 256;
    numObjects = 100000;

    attributes = (float**)calloc(numObjects, sizeof(float*));
    if (!attributes) exit(1);

    for (int idx = 0; idx < numObjects; idx++) {
        attributes[idx] = (float*)malloc(numAttributes * sizeof(float));
        if (!attributes[idx]) exit(1);
    }
}

void loop();