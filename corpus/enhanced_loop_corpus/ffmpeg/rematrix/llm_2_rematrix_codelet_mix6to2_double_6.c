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
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < len; i += 2) {
        if (i + 1 < len) {
            // Process two elements at once with stride handling
            double t0 = in[2][i] * (double)coeffp[0 * 6 + 2] + in[3][i] * (double)coeffp[0 * 6 + 3];
            double t1 = in[2][i+1] * (double)coeffp[0 * 6 + 2] + in[3][i+1] * (double)coeffp[0 * 6 + 3];

            out[0][i]   = t0 + in[0][i]   * (double)coeffp[0 * 6 + 0] + in[4][i]   * (double)coeffp[0 * 6 + 4];
            out[0][i+1] = t1 + in[0][i+1] * (double)coeffp[0 * 6 + 0] + in[4][i+1] * (double)coeffp[0 * 6 + 4];

            out[1][i]   = t0 + in[1][i]   * (double)coeffp[1 * 6 + 1] + in[5][i]   * (double)coeffp[1 * 6 + 5];
            out[1][i+1] = t1 + in[1][i+1] * (double)coeffp[1 * 6 + 1] + in[5][i+1] * (double)coeffp[1 * 6 + 5];
        } else {
            // Handle odd-sized len
            double t = in[2][i] * (double)coeffp[0 * 6 + 2] + in[3][i] * (double)coeffp[0 * 6 + 3];
            out[0][i] = t + in[0][i] * (double)coeffp[0 * 6 + 0] + in[4][i] * (double)coeffp[0 * 6 + 4];
            out[1][i] = t + in[1][i] * (double)coeffp[1 * 6 + 1] + in[5][i] * (double)coeffp[1 * 6 + 5];
        }
    }
}
