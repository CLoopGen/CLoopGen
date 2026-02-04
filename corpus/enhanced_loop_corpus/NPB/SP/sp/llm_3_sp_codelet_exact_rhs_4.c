#include <stdio.h>

extern  int grid_points[3];
extern  double forcing[5][65][65][65];
extern int m;
extern int i;
extern int j;
extern int k;



void loop(){
    // Variant 2: Memory Access Pattern Modification - Convert to consecutive memory access by flattening indices
    // We reinterpret the 4D array as a linear traversal to ensure sequential memory writes, which improves spatial locality.
    long total_size = 5 * grid_points[0] * grid_points[1] * grid_points[2];
    double *forcing_flat = &forcing[0][0][0][0];
    
    for (long idx = 0; idx < total_size; idx++) {
        forcing_flat[idx] = 0.0;
    }
}
