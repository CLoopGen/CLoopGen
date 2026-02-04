#include <stdio.h>

#include <inttypes.h>

extern int xpam120[23][23];
extern char *dsq;
extern int len;
extern int i;
extern int k;
extern int off;
extern int sum;
extern int beg;
extern int end;
extern int top;
extern int topcut;
extern int fallcut;
extern int noff;
extern int mcut;
extern int *hit;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing dsq[i] and dsq[i - off], we stride by 2 to create a strided access pattern.
    // This changes the memory access to every second element, potentially improving cache behavior
    // for certain data layouts or enabling vectorization with stride handling.

    for (off = mcut; off <= noff; off++) {
        sum = top = 0;
        beg = off;
        end = 0;
        // Stride by 2 in the inner loop to create regular strided access
        for (i = off + 1; i <= len; i += 2) {
            // Ensure we don't go out of bounds when striding
            if (i + 1 <= len) {
                // Process two elements at once with stride
                sum += xpam120[(int)dsq[i]][(int)dsq[i - off]];
                if (sum > top) {
                    top = sum;
                    end = i;
                }
                sum += xpam120[(int)dsq[i+1]][(int)dsq[i+1 - off]];
                if (sum > top) {
                    top = sum;
                    end = i + 1;
                }
            } else {
                // Handle last odd element
                sum += xpam120[(int)dsq[i]][(int)dsq[i - off]];
                if (sum > top) {
                    top = sum;
                    end = i;
                }
            }
            if (top >= topcut && top - sum > fallcut) {
                for (k = beg; k <= end; k++)
                    hit[k] = hit[k - off] = 1;
                sum = top = 0;
                beg = end = i + 2;
            } else if (top - sum > fallcut) {
                sum = top = 0;
                beg = end = i + 2;
            }
            if (sum < 0) {
                beg = end = i + 2;
                sum = top = 0;
            }
        }
        if (top >= topcut) {
            for (k = beg; k <= end; k++)
                hit[k] = hit[k - off] = 1;
        }
    }
}
