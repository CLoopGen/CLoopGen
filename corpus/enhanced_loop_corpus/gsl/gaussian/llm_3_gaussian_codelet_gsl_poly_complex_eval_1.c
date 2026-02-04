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
    // Variant 2: Indirect memory access using an index mapping array
    // Simulate indirect access via a lookup table (emulated with arithmetic since no additional arrays allowed)
    // Here, we reverse the access order: accessing c by mirrored index (len - 1 - i)
    int *indices = (int*)alloca(len * sizeof(int));
    for (int j = 0; j < len; j++) {
        indices[j] = len - 1 - j;  // reversed indexing
    }
    for (i = len - 1; i > 0; i--) {
        int idx = indices[i];      // indirect access via index remapping
        int prev_idx = (idx > 0) ? indices[i - 1] : 0;
        double tmp = (idx > 0) ? c[prev_idx] + (z.dat[0]) * (ans.dat[0]) - (z.dat[1]) * (ans.dat[1]) : ans.dat[0];
        ans.dat[1] = (z.dat[1]) * (ans.dat[0]) + (z.dat[0]) * (ans.dat[1]);
        ans.dat[0] = tmp;
    }
}
