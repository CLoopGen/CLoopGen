#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern void *Y;
extern  int incY;
extern int i;
extern  double beta_real;
extern  double beta_imag;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with precomputed pointer offset
    // Instead of recalculating 2*(iy) each time, use a running byte/element offset.
    // This emphasizes stride-based traversal where incY defines the step in complex elements.
    double *Yd = (double *)Y;
    int offset = 0; // Tracks current position in doubles (each complex number uses 2 doubles)
    for (i = 0; i < N; i++) {
        const double y_real = Yd[offset];
        const double y_imag = Yd[offset + 1];
        const double tmpR = y_real * beta_real - y_imag * beta_imag;
        const double tmpI = y_real * beta_imag + y_imag * beta_real;
        Yd[offset] = tmpR;
        Yd[offset + 1] = tmpI;
        offset += 2 * incY; // Stride by incY in complex elements → 2*incY in doubles
    }
}
