#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double y;
extern  int M;
extern double sum;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access pattern using index indirection
    // Create an indirect access sequence (e.g., reverse order access via index mapping)
    int* indices = (int*)malloc(M * sizeof(int));
    double local_sum = sum;

    // Construct reversed index mapping (indirect access pattern)
    for (int i = 0; i < M; i++) {
        indices[i] = M - i;  // Reverse order: access from M down to 1
    }

    // Traverse based on the indirect index array
    for (int i = 0; i < M; i++) {
        int n_val = indices[i];
        local_sum += 1. / (n_val * (n_val * n_val + y * y));
    }

    sum = local_sum;
    free(indices);
}
