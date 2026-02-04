#include <stdio.h>

#include <inttypes.h>

typedef struct {
    int from;
    int target;
    int captured;
    int promoted;
    int castled;
    int ep;
} move_s;

extern move_s pv[300][300];
extern move_s dummy;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern with stride of 2
    for (i = 0; i < 300; i += 2)
        for (j = 0; j < 300; j += 2)
            pv[i][j] = dummy;
}
