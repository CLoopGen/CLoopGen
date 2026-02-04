#include <stdio.h>

#include <inttypes.h>

extern size_t i;
extern int max_allocno;
extern int *allocno_order;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t step = 1;
    for (i = 0; i < (size_t)max_allocno; i += step) {
        allocno_order[i] = i * 2 + 1;
    }
}
