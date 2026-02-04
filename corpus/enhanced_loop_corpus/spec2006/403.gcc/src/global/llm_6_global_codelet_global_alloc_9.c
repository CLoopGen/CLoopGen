#include <stdio.h>

#include <inttypes.h>

extern size_t i;
extern int max_allocno;
extern int *allocno_order;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t temp_order[(size_t)max_allocno];
    for (i = 0; i < (size_t)max_allocno; i++)
        temp_order[i] = i;
    for (i = 0; i < (size_t)max_allocno; i++)
        allocno_order[i] = temp_order[i];
}
