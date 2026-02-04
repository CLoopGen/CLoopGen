#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

void *Y;
int incY;
int i;
int lenY;
double beta_real;
double beta_imag;
int iy;

void init_vars() {
    const size_t element_size = 2 * sizeof(double); // Each complex number has real and imaginary parts
    const size_t total_size = 64 * 1024 * 1024; // Aim for ~64MB to target ~0.01s runtime on modern CPU
    lenY = total_size / element_size;
    
    // Allocate Y as array of double pairs (complex numbers)
    Y = aligned_alloc(32, total_size);
    
    // Initialize beta values for complex scaling
    beta_real = 1.5;
    beta_imag = 0.8;
    
    // Set stride and initial index
    incY = 1;
    iy = 0;
    
    // Ensure iy + (lenY-1)*incY doesn't exceed bounds
    // Initialize Y with sample data to avoid undefined behavior
    double *Yd = (double *)Y;
    for (int idx = 0; idx < lenY; idx++) {
        int offset = 2 * (idx * incY);
        Yd[offset]     = (double)(idx % 100) * 0.1;  // real part
        Yd[offset + 1] = (double)(idx % 75) * 0.2;  // imag part
    }
}