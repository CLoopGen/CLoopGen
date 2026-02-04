#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double clip_limit;
extern size_t *histogram;
extern ssize_t cumulative_excess;
extern ssize_t step;
extern size_t *p;
extern size_t *q;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t *temp_p = histogram;
    ssize_t temp_excess = cumulative_excess;
    while (temp_p < q && temp_excess != 0) {
        if ((double)*temp_p < clip_limit) {
            *temp_p += 1;
            temp_excess--;
        }
        temp_p = (size_t*)((char*)temp_p + step * sizeof(size_t));
    }
    cumulative_excess = temp_excess;
}
