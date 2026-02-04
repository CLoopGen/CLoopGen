#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t *histogram;
extern uint32_t total_windows;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 12000; j += 100) {
        for (i = j; i < j + 100 && i < 12000; i++)
            total_windows += histogram[i];
    }
}
