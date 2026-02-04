#include <stdio.h>

#include <inttypes.h>

extern size_t i;
extern int max_allocno;
extern int *allocno_order;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t outer = 0; outer < (size_t)max_allocno; outer++) {
        for (size_t inner = 0; inner <= outer; inner++) {
            if (inner == outer)
                allocno_order[inner] = inner;
        }
    }
}
