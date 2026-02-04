#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    double dat[2];
} gsl_complex;

extern  double c[];
extern  int len;
extern  gsl_complex z;
extern int i;
extern gsl_complex ans;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Consecutive forward traversal using pointer arithmetic for consecutive access
    // Reverses the original direction and accesses elements consecutively from start to end
    // Simulates a transformed dependency chain by reversing loop order and adjusting indexing
    double* c_ptr = c;
    ans.dat[0] = c[len - 1];  // Initialize real part with last coefficient
    ans.dat[1] = 0.0;         // Clear imaginary part initially

    for (i = 0; i < len - 1; i++) {
        double tmp = c_ptr[i] + z.dat[0] * ans.dat[0] - z.dat[1] * ans.dat[1];
        ans.dat[1] = z.dat[1] * ans.dat[0] + z.dat[0] * ans.dat[1];
        ans.dat[0] = tmp;
    }
}
