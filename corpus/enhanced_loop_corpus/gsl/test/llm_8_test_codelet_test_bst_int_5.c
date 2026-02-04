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
    for (i = 0; i < (int)n; i += 2) {
        sorted_data[i] = data[i];
        if (i + 1 < (int)n)
            sorted_data[i + 1] = data[i + 1];
    }
}
