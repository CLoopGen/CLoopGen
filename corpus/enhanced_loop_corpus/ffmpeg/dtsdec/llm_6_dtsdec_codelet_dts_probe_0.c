#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int markers[64];
extern int sum;
extern int max;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_sum = 0;
    int temp_max = 0;
    for (i = 0; i < (sizeof (markers) / sizeof ((markers)[0])); i++) {
        temp_sum += markers[i];
        if (i > 0 && markers[temp_max] < markers[i]) {
            temp_max = i;
        }
    }
    sum = temp_sum;
    max = temp_max;
}
