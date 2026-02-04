#include <stdio.h>

#include <inttypes.h>

extern unsigned char *to;
extern int num;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i <= num; i++) {
        to[i-1] = 0;      // Remove loop-carried dependence; write is independent across iterations
    }
    if (num > 0)
        to[num-1] = 0;    // Eliminate potential redundancy (WAW) by ensuring last write is explicit but redundant
}
