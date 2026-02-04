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
    for (i = 0; i < (int)n; ++i) {
        if (i > 0)
            data_delete[i] = sorted_data[i] + data_delete[i-1];
        else
            data_delete[i] = sorted_data[i];
    }
}
