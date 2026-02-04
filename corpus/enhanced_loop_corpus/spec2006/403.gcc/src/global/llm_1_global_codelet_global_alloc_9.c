#include <stdio.h>

#include <inttypes.h>

extern size_t i;
extern int max_allocno;
extern int *allocno_order;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t limit = (size_t)max_allocno;
    for (size_t i = 0; i < limit; i += 2) {
        allocno_order[i] = i;
        if (i + 1 < limit)
            allocno_order[i + 1] = i + 1;
    }
}
