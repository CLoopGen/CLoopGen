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
    // Variant 1: Consecutive memory access with reversed traversal (unrolled by 2)
    // Access pattern changed to process two elements per iteration when possible
    int i = len - 1;
    if ((len & 1) == 0 && len >= 2) {
        for (; i > 1; i -= 2) {
            double tmp1 = c[i - 1] + z.dat[0] * ans.dat[0] - z.dat[1] * ans.dat[1];
            double tmp_im1 = z.dat[1] * ans.dat[0] + z.dat[0] * ans.dat[1];
            double tmp0 = c[i - 2] + z.dat[0] * tmp1 - z.dat[1] * tmp_im1;
            double tmp_im0 = z.dat[1] * tmp1 + z.dat[0] * tmp_im1;

            ans.dat[0] = tmp0;
            ans.dat[1] = tmp_im0;
        }
    }
    // Handle remaining element if any
    for (; i > 0; i--) {
        double tmp = c[i - 1] + z.dat[0] * ans.dat[0] - z.dat[1] * ans.dat[1];
        ans.dat[1] = z.dat[1] * ans.dat[0] + z.dat[0] * ans.dat[1];
        ans.dat[0] = tmp;
    }
}
