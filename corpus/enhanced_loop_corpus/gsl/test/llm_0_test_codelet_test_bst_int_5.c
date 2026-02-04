#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t n;
extern int *data;
extern int *sorted_data;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t outer = 0; outer < (n + 1) / 2; ++outer) {
        for (i = outer * 2; i < (int)n && i < (int)(outer * 2 + 2); ++i)
            sorted_data[i] = data[i];
    }
}
