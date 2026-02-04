#include <stdio.h>

#include <inttypes.h>

extern  uint64_t *a;
extern uint64_t aa[4];
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; i += 2) {
        aa[i % 4] = a[i] + a[i + 1] + a[i + 4] + a[i + 5];
    }
}
