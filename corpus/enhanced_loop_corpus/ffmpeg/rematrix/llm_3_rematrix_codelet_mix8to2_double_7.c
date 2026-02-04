#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern double **out;
extern  double **in;
extern double *coeffp;
extern integer len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < len; i++) {
    int idx = i; // Simulate indirect access via index vector (trivial mapping here, but extensible)
    int j = idx;
    
    // Reorder memory accesses to group by input array for better spatial locality
    double in0 = in[0][j], in1 = in[1][j], in2 = in[2][j], in3 = in[3][j];
    double in4 = in[4][j], in5 = in[5][j], in6 = in[6][j], in7 = in[7][j];
    
    double coeff_0_2 = (double)coeffp[0 * 8 + 2];
    double coeff_0_3 = (double)coeffp[0 * 8 + 3];
    double t = in2 * coeff_0_2 + in3 * coeff_0_3;
    
    out[0][j] = t + in0 * (double)coeffp[0 * 8 + 0] + in4 * (double)coeffp[0 * 8 + 4] + in6 * (double)coeffp[0 * 8 + 6];
    out[1][j] = t + in1 * (double)coeffp[1 * 8 + 1] + in5 * (double)coeffp[1 * 8 + 5] + in7 * (double)coeffp[1 * 8 + 7];
}
}
