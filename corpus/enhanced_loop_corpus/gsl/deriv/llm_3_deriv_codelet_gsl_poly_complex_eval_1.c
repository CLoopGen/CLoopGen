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
    // Variant 2: Indirect memory access using an index map (simulated via offset array)
    // Create a local indirect access pattern by accessing c[] through an index permutation
    int *indices = (int*)malloc(sizeof(int) * len);
    if (!indices) return; // handle allocation failure

    // Build reverse-stride index map: access every other element in reverse
    int j = 0;
    for (int idx = len - 1; idx >= 0; idx -= 1) {
        indices[j++] = idx;
    }

    // Traverse with indirect addressing
    for (i = 0; i < len - 1; i++) {
        int current_idx = indices[i];
        int prev_idx = (current_idx > 0) ? current_idx - 1 : 0;

        double tmp = c[prev_idx] + z.dat[0] * ans.dat[0] - z.dat[1] * ans.dat[1];
        ans.dat[1] = z.dat[1] * ans.dat[0] + z.dat[0] * ans.dat[1];
        ans.dat[0] = tmp;
    }

    free(indices);
}
