#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t size1;
extern  size_t size2;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int** data = (int**)malloc(size1 * sizeof(int*));
    for (i = 0; i < size1; i++) {
        data[i] = (int*)calloc(size2, sizeof(int));
        for (j = 0; j < size2; j++) {
            if (i > 0) {
                data[i][j] = data[i-1][j] + 1; // Introduce RAW dependency: current iteration depends on previous i
            } else {
                data[i][j] = 0;
            }
        }
    }
    free(data[0]);
    free(data);
}
