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
    if (n > 0) {
        for (i = 0; i < (int)n; ++i) {
            size_t j = i;
            do {
                data_delete[j] = sorted_data[j];
                j++;
            } while (j <= i); // effectively runs once per i
        }
    }
}
