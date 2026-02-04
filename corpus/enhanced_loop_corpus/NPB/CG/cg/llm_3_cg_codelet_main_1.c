#include <stdio.h>

extern  int firstrow;
extern  int lastrow;
extern  int firstcol;
extern  int colidx[2198001];
extern  int rowstr[14002];
extern int j;
extern int k;



void loop(){
    // Variant 2: Strided Memory Access Pattern
    // Modify access to colidx by introducing a strided traversal within each row segment.
    // This changes the memory access from sequential to strided (e.g., every 2nd element forward, then backward).
    for (j = 1; j <= lastrow - firstrow + 1; j++) {
        int start = rowstr[j];
        int end = rowstr[j + 1];
        int length = end - start;

        // Forward pass: even indices in the local segment
        for (k = start; k < start + (length & ~1); k += 2) {
            colidx[k] = colidx[k] - firstcol + 1;
        }

        // Backward pass: odd indices in the local segment
        if (length > 1) {
            for (k = start + (length % 2 == 0 ? length - 1 : length - 2); k >= start + 1; k -= 2) {
                colidx[k] = colidx[k] - firstcol + 1;
            }
        }

        // Handle middle element if length is odd and not covered
        if (length % 2 == 1) {
            colidx[start + length - 1] = colidx[start + length - 1] - firstcol + 1;
        }
    }
}
