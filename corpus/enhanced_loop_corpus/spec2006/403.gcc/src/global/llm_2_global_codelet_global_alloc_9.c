#include <stdio.h>

#include <inttypes.h>

extern size_t i;
extern int max_allocno;
extern int *allocno_order;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t step = 2;
    size_t j;
    for (j = 0; j < (size_t)max_allocno; j += step) {
        if (j < (size_t)max_allocno) allocno_order[j] = j;
    }
    for (j = 1; j < (size_t)max_allocno; j += step) {
        if (j < (size_t)max_allocno) allocno_order[j] = j;
    }
}
