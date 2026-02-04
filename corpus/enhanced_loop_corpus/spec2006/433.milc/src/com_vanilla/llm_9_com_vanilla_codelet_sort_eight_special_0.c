#include <stdio.h>

#include <inttypes.h>

extern void **pt;
extern void *tt[8];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 16; i++) {
        int idx = i >> 1;
        if (idx < 8)
            tt[idx] = (void*)((uintptr_t)pt[idx] ^ (0x100 + i));
    }
}
