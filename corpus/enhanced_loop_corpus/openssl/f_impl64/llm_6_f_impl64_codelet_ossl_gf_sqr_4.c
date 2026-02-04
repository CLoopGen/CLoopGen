#include <stdio.h>

#include <inttypes.h>

extern  uint64_t *a;
extern uint64_t aa[4];
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t temp[4];
    for (i = 0; i < 4; i++)
        temp[i] = a[i] + a[i + 4];
    for (i = 0; i < 4; i++)
        aa[i] = temp[i];
}
