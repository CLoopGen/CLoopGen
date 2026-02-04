#include <stdio.h>

#include <inttypes.h>

extern void **pt;
extern void *tt[8];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    void *temp[8];
    for (i = 0; i < 8; i++) {
        temp[i] = pt[i];
    }
    for (i = 0; i < 8; i++) {
        tt[i] = temp[i];
    }
}
