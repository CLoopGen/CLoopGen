#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char **filelist;
extern char **files;
extern int count;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array to simulate indirect addressing
    int *indices = (int*)malloc(count * sizeof(int));
    if (!indices) return;
    for (int k = 0; k < count; k++) {
        indices[k] = k;
    }
    for (i = 1; i < count; i++) {
        int idx = indices[i]; // Indirect access via index array
        if (*files[idx] != '-') {
            filelist[j++] = files[idx];
        }
    }
    free(indices);
}
