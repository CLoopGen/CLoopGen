#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t MPA_INT;

extern MPA_INT *window;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; i++) {
        for (int temp_j = 0; temp_j < 4; temp_j++) {
            for (j = 0; j < 4; j++) {
                int actual_j = 4 * temp_j + j;
                window[512 + 128 + 16 * i + actual_j] = window[64 * i + 48 - actual_j];
            }
        }
    }
}
