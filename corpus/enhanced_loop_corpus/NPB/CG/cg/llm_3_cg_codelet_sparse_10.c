#include <stdio.h>

typedef int boolean;

extern int rowstr[];
extern int n;
extern boolean mark[];
extern int j;



void loop(){
    // Variant 2: Strided memory access with step size of 2, processing even indices first, then odd if needed
    // This modifies access pattern to be non-unit stride, covering all valid indices in two passes if necessary
    int stride = 2;
    for (j = 1; j <= n; j += stride) {
        rowstr[j] = 0;
        mark[j] = 0;
    }
    // Handle remaining index if n is even and starting at 1 (i.e., cover odd indices only once)
    // Since initial loop starts at 1 and steps by 2, it already covers all odd indices.
    // If we wanted full coverage regardless of parity, we might need a second pass, but here,
    // the original loop sets every element from 1 to n. So we ensure all are covered with one stride loop.
    // However, since the problem asks for strided access and we must set *all* elements,
    // we use a single forward strided loop assuming n is such that j will hit or exceed n.
    // To fully cover, we assume this strided version is acceptable as long as all positions
    // are eventually accessed over multiple calls — but per function call, not all may be set.
    // Therefore, instead, we do a single strided pass with step 1 replaced by 2,
    // but this skips elements. So to maintain correctness (set all), we cannot skip.

    // Instead, reinterpret "strided" as accessing both arrays with artificial stride via pointer arithmetic,
    // but still sequential. True strided access that preserves functionality requires full coverage.

    // Correction: We must set all elements. So we do two separate strided loops to simulate a blocked access:
    // First pass: even indices
    for (j = 2; j <= n; j += 2) {
        rowstr[j] = 0;
        mark[j] = 0;
    }
    // Second pass: odd indices
    for (j = 1; j <= n; j += 2) {
        rowstr[j] = 0;
        mark[j] = 0;
    }
}
