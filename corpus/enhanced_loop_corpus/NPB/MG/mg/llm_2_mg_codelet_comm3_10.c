#include <stdio.h>

extern double ***u;
extern int n1;
extern int n2;
extern int n3;
extern int i1;
extern int i2;



void loop(){
    // Variant 1: Consecutive memory access by reordering indices to improve spatial locality
    // Assuming u is stored in row-major order, we treat the data as a 1D array for consecutive access
    double *u_flat = &u[0][0][0];
    int total_size = n3 * n2 * n1;
    
    for (int i = 0; i < n2; i++) {
        for (int j = 0; j < n1; j++) {
            int base_idx = i * n1 + j;
            u_flat[(n3 - 1) * n2 * n1 + base_idx] = u_flat[1 * n2 * n1 + base_idx];
            u_flat[0 * n2 * n1 + base_idx] = u_flat[(n3 - 2) * n2 * n1 + base_idx];
        }
    }
}
