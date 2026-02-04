#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int arr[1000];
    int indices[4] = {5, 10, 15, 20}; // Strided access pattern
    for (i = 0; i < 1000 / 4UL; i++) {
        for (j = 0; j < 4; j++) {
            arr[(i * 25) + indices[j]] = i * j; // Strided and non-consecutive memory access
        }
    }
}
