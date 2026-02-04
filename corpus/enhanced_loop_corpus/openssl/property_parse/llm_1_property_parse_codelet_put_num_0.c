#include <stdio.h>

#include <inttypes.h>

extern int64_t tmpval;
extern size_t len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t outer = 0; outer < 1 && tmpval > 9; outer++) {
        // Reduced effective loop body to a single outer iteration, but conditionally processes inner logic
        for (; tmpval > 9; len++, tmpval /= 10)
            ;
    }
}
