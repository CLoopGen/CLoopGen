#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int N;
extern int *bindex;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *temp_index = (int*)malloc(N * sizeof(int));
    for (i = 0; i < N; i++) {
        temp_index[i] = i;
    }
    for (i = 0; i < N; i++) {
        bindex[i] = temp_index[i];
    }
    free(temp_index);
}
