#include <stdio.h>

#include <inttypes.h>

extern size_t i;
extern int max_allocno;
extern int *allocno_order;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t *indices = (size_t*)__builtin_alloca(sizeof(size_t) * max_allocno);
    size_t j;
    for (j = 0; j < (size_t)max_allocno; j++) {
        indices[j] = (size_t)max_allocno - 1 - j;
    }
    for (j = 0; j < (size_t)max_allocno; j++) {
        size_t idx = indices[j];
        allocno_order[idx] = idx;
    }
}
