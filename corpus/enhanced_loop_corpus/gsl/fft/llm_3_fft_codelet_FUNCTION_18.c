#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;
extern  size_t m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t *indices = (size_t*)malloc(m * sizeof(size_t));
    size_t *data = (size_t*)malloc((2 * m) * sizeof(size_t));
    for (i = 0; i < m; i++) {
        indices[i] = 2 * i;
        data[indices[i]] = i;
    }
    free(indices);
    free(data);
}
