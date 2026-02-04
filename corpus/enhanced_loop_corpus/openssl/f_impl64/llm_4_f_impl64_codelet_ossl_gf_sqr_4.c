#include <stdio.h>

#include <inttypes.h>

extern  uint64_t *a;
extern uint64_t aa[4];
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; ++i) {
        if ((a[i] | a[i + 4]) != 0) {
            aa[i] = a[i] + a[i + 4];
        } else {
            aa[i] = 0;
        }
    }
}
