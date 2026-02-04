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
    int j;
    for (i = 0; i < (int)n; ++i) {
        int val = data[i];
        for (j = 0; j < 3; ++j) {
            val += j;  
        }
        sorted_data[i] = val - 3; 
    }
}
