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
        sorted_data[0] = data[0];
        for (i = 1; i < (int)n; ++i) {
            sorted_data[i] = sorted_data[i-1] + data[i] - data[i-1];
        }
    }
}
