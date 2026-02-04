#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t *histogram;
extern uint32_t total_windows;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 12000; i++) {
        if (histogram[i] > 0) {
            total_windows += histogram[i];
        }
    }
}
