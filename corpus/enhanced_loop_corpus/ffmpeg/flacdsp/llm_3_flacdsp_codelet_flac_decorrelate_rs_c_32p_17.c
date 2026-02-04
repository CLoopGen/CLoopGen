#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t **in;
extern int len;
extern int shift;
extern int32_t **samples;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int *indices = (int*)alloca(len * sizeof(int));
for (int j = 0; j < len; j++) {
    indices[j] = j;
}
for (int j = 0; j < len; j++) {
    int idx = indices[j]; // Indirect access via index array
    unsigned int a = in[0][idx];
    unsigned int b = in[1][idx];
    (samples[0][idx]) = (a + b) << shift;
    (samples[1][idx]) = b << shift;
}
}
