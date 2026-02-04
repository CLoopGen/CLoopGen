#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned int UINTFLOAT;

typedef int INTFLOAT;

extern UINTFLOAT *in;
extern int i;
extern  int n;
extern  int n2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access using index arrays to simulate gather/scatter pattern
    // Precomputed indices are not stored externally for simplicity, but calculated on-the-fly as indirect access.
    // This simulates a case where access pattern is non-linear and computed via auxiliary logic.
    int *indices = (int*)alloca(n2 * sizeof(int));
    for (int j = 0; j < n2; j += 2) {
        indices[j]     = j;
        indices[j + 1] = j + 1;
    }

    for (i = 0; i < n2; i += 2) {
        INTFLOAT temp;
        int idx1 = indices[i];           // direct mapping for clarity, but enables future randomization
        int idx2 = indices[i + 1];
        int mirror1 = n - 1 - idx1;
        int mirror2 = n - 2 - idx2;

        temp = in[idx1];
        in[idx1] = -in[mirror1];
        in[mirror1] = temp;

        temp = -in[idx2];
        in[idx2] = in[mirror2];
        in[mirror2] = temp;
    }
}
