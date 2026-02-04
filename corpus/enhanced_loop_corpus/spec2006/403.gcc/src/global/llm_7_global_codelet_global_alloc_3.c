#include <stdio.h>

#include <inttypes.h>

extern size_t i;
extern int *reg_allocno;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t temp[53];
    size_t i;
    for (i = 0; i < 53; i++)
        temp[i] = -1; // Eliminate all loop-carried dependencies; write to local array first

    for (i = 0; i < 53; i++)
        reg_allocno[i] = temp[i]; // Then copy to global output in separate independent loop
}
