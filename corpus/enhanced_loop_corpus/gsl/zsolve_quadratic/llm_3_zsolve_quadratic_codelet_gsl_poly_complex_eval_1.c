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
    // Variant 2: Consecutive forward traversal with offset indexing
    // Simulate reversed order processing using a mapped index, but traverse forward
    for (i = 0; i < len - 1; i++) {
        int rev_idx = len - 1 - i;  // Reverse mapping: from end to start
        int prev_idx = rev_idx - 1;
        double tmp = c[prev_idx] + z.dat[0] * ans.dat[0] - z.dat[1] * ans.dat[1];
        ans.dat[1] = z.dat[1] * ans.dat[0] + z.dat[0] * ans.dat[1];
        ans.dat[0] = tmp;
    }
}
