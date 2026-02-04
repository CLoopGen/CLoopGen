#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint64_t histdb[92];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = -1;
    for (i = 0; i <= 91; i++) {
        if (!histdb[i] && temp == -1) {
            temp = i;
        }
    }
    i = temp;
}
