#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint64_t count;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t temp_count = count;
    for (i = 0; i < 1000000000 / 4UL; i++) {
        for (j = 0; j < 4; j++) {
            temp_count++;
        }
    }
    count = temp_count;
}
