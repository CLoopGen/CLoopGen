#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double c[];
extern  int len;
extern  double x;
extern int i;
extern double ans;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated via computed indices)
    // Instead of direct c[i-1], we use a virtual "indirection" through arithmetic offset
    // Simulate indirect access by reversing the effective index mapping
    ans = 0.0; // Ensure initialization
    int n = len - 1;
    for (i = len - 1; i > 0; i--) {
        int idx = n - (i - 1); // indirect-like indexing: reverse order of access into c
        if (idx < len && idx >= 0)
            ans = c[idx] + x * ans;
    }
}
