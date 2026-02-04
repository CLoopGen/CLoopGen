#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *window;
extern int i;
extern int n;
extern int n2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *indices = (int*)malloc(n2 * sizeof(int));
    for (int j = 0; j < n2; j++) {
        indices[j] = n2 - 1 - j;
    }
    for (i = 0; i < n2; i++) {
        window[n - 1 - indices[i]] = window[indices[i]];
    }
    free(indices);
}
