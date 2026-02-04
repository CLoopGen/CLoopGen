#include <stdio.h>

#include <inttypes.h>

extern size_t i;
extern int max_allocno;
extern int *allocno_order;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (size_t)max_allocno; i++) {
        size_t prev = (i == 0) ? 0 : allocno_order[i - 1];
        allocno_order[i] = prev + 1;
    }
}
