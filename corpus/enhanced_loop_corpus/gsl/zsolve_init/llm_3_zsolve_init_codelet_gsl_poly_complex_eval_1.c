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
    // Variant 2: Indirect memory access using an index array (simulated via arithmetic)
    // We simulate indirect access by accessing c[(i-1)*3 % len] to create non-consecutive, scattered reads.
    // This models a more irregular, indirect-like access pattern.
    for (i = len - 1; i > 0; i--) {
        int idx = (i - 1) * 3 % len;  // Indirect-like indexing with wrap-around
        double tmp = c[idx] + z.dat[0] * ans.dat[0] - z.dat[1] * ans.dat[1];
        ans.dat[1] = z.dat[1] * ans.dat[0] + z.dat[0] * ans.dat[1];
        ans.dat[0] = tmp;
    }
}
