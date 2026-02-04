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
    for (size_t *outer = histogram; outer < q && cumulative_excess != 0; outer += (ptrdiff_t)step) {
        for (size_t *inner = outer; inner < outer + 1 && cumulative_excess != 0; inner++) {
            if ((double)*inner < clip_limit) {
                (*inner)++;
                cumulative_excess--;
            }
        }
    }
}
