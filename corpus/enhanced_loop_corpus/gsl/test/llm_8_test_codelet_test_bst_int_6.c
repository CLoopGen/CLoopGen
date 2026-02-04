#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t n;
extern int *data_delete;
extern int *sorted_data;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (i = 0; i < (int)n; ++i) {
        data_delete[i] = sorted_data[i];
        for (j = 0; j < 3; ++j) {
            data_delete[i] += j; 
        }
    }
}
