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
    int step = 2;
    for (i = 0; i < (int)n; i += step) {
        data_delete[i] = sorted_data[i];
        if (i + 1 < (int)n) {
            data_delete[i + 1] = sorted_data[i + 1];
        }
    }
}
