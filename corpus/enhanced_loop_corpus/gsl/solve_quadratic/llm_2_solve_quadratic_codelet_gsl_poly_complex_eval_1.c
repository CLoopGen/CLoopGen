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
    // Variant 1: Strided memory access (access every 2nd element in reverse, with stride of 2)
    // This changes the iteration pattern to skip elements, creating a strided access on array c.
    for (i = ((len - 1) | 1); i > 0; i -= 2) {  // Align start to odd index and step by 2
        int idx = i - 1;  // Access c[idx], where idx decreases by 2 each time
        double tmp = c[idx] + z.dat[0] * ans.dat[0] - z.dat[1] * ans.dat[1];
        ans.dat[1] = z.dat[1] * ans.dat[0] + z.dat[0] * ans.dat[1];
        ans.dat[0] = tmp;
        // If we are at i=1, break before going below 0 after next step
        if (i == 1) break;
    }
}
