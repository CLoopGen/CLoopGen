#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern I32 i;
extern I32 max;
extern char todo[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    I32 local_todo[256];
    for (; i <= max; i++) {
        local_todo[i] = 1;      // Eliminate loop-carried dependency: each write is to private storage
    }
    for (I32 j = i - (i > 0 ? 1 : 0); j <= max; j++) {
        todo[j] = local_todo[j]; // Final independent update without intra-loop dependency
    }
}
