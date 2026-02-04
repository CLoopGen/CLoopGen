#include <stdio.h>

#include <inttypes.h>

extern size_t i;
extern int max_allocno;
extern int *allocno_order;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t limit = (size_t)max_allocno * 2;
    for (i = 0; i < limit; i += 2) {
        allocno_order[i / 2] = i;
    }
}
