#include <stdio.h>

#include <inttypes.h>

typedef long longword;

extern longword *L_ACF;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive forward traversal with index remapping
    longword indices[9] = {0,1,2,3,4,5,6,7,8};
    for (k = 0; k < 9; k++) {
        L_ACF[indices[k]] = 0;
    }
}
