#include <stdio.h>

#include <inttypes.h>

extern int *r;
extern int size;
extern int i;
extern int max_r;
extern int min_r;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int temp_max = min_r;
    int temp_min = max_r;
    for (i = 0; i < size; i++) {
        temp_max = (r[i] > temp_max) ? r[i] : temp_max;
        temp_min = (r[i] < temp_min) ? r[i] : temp_min;
    }
    max_r = temp_max;
    min_r = temp_min;
}
