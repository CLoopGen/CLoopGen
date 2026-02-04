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
    if (n > 0) {
        i = 0;
        for (size_t block_start = 0; block_start < n; block_start += n) {
            for (; i < (int)n; ++i)
                sorted_data[i] = data[i];
        }
    }
}
