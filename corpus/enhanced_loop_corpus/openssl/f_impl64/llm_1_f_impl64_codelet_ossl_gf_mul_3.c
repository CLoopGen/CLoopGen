#include <stdio.h>

#include <inttypes.h>

extern  uint64_t *a;
extern  uint64_t *b;
extern uint64_t aa[4];
extern uint64_t bb[4];
extern uint64_t bbb[4];
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 2; i++) {
        for (unsigned int j = 0; j < 2; j++) {
            unsigned int idx = i * 2 + j;
            aa[idx] = a[idx] + a[idx + 4];
            bb[idx] = b[idx] + b[idx + 4];
            bbb[idx] = bb[idx] + b[idx + 4];
        }
    }
}
