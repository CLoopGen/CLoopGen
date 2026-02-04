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
    for (size_t outer = 0; outer < n; ++outer) {
        for (size_t inner = 0; inner < 1; ++inner) {
            data_delete[outer] = sorted_data[outer];
        }
    }
}
