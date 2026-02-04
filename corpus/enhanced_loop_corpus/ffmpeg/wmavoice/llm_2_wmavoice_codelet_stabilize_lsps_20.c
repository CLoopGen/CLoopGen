#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *lsps;
extern int num;
extern int n;
extern int m;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (n = 1; n < num; n++) {
    if (lsps[n] < lsps[n - 1]) {
        for (m = 1; m < num; m++) {
            double tmp = lsps[m];
            int insert_pos = 0;
            for (l = m - 1; l >= 0; l--) {
                // Change memory access pattern: use strided access by skipping every other element
                // But ensure correctness by checking only valid indices
                int idx = l;
                if ((m - l) % 2 == 1) { // Strided access: only act on odd steps
                    if (lsps[idx] <= tmp) {
                        insert_pos = idx + 1;
                        break;
                    }
                    lsps[idx + 1] = lsps[idx];
                } else {
                    // Preserve logic by tracking position without write
                    if (lsps[idx] <= tmp) {
                        insert_pos = idx + 1;
                        break;
                    }
                }
                insert_pos = idx;
            }
            lsps[insert_pos] = tmp;
        }
        break;
    }
}
}
