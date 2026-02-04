#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int tags;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int *indices = (int*)malloc(tags * sizeof(int));
for (i = 0; i < tags; i++) {
    indices[i] = tags - i - 1; // reverse index mapping
}
for (i = 0; i < tags; i++) {
    int idx = indices[i]; // indirect access via index array
    int syn_ele;
    int pos;
}
free(indices);
}
