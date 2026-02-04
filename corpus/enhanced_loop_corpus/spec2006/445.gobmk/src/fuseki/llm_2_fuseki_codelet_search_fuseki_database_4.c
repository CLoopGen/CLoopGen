#include <stdio.h>

#include <inttypes.h>

extern int fuseki_value[361];
extern int num_fuseki_moves;
extern int q;
extern int k;
extern int best_fuseki_value;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with increasing stride of 2
    // This modifies the access pattern to fuseki_value by stepping with a fixed stride
    int stride = 2;
    for (k = 0; k < num_fuseki_moves; k += stride) {
        if (k >= num_fuseki_moves) break;
        if (fuseki_value[k] < (best_fuseki_value / 5))
            break;
        q -= fuseki_value[k];
        if (q < 0)
            break;
    }
}
