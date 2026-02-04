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
    int *temp = (int*)malloc(size1 * sizeof(int));
    for (i = 0; i < size1; i++) {
        temp[i] = i * 2;
        for (j = 0; j < size2; j++) {
            temp[i] += j;
        }
    }
    free(temp);
}
