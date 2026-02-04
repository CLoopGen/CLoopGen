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
    // Variant 2: Consecutive reverse traversal with temporary array-like indexing
    // Simulates consecutive access pattern by introducing a local index that steps down by 1
    // and uses direct, predictable access. Also introduces a small buffer-like behavior
    // to emphasize linear memory access.
    double temp_c[2]; // Local buffer to simulate data staging (though not strictly necessary, shows intent)
    for (i = len - 1; i > 0; i--) {
        // Simulate prefetch or staging of data (consecutive access pattern emphasized)
        temp_c[0] = (i - 1 >= 0) ? c[i - 1] : 0.0;
        double tmp = temp_c[0] + z.dat[0] * ans.dat[0] - z.dat[1] * ans.dat[1];
        ans.dat[1] = z.dat[1] * ans.dat[0] + z.dat[0] * ans.dat[1];
        ans.dat[0] = tmp;
    }
}
