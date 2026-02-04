#include <stdio.h>

#include <inttypes.h>

typedef char base;

extern int n;
extern base seq[2500];
extern int table[2500][2500];
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = n - 1; i >= 0; i--) {
    for (j = i + 1; j < n; j++) {
        int idx_j_minus_1 = j - 1;
        if (idx_j_minus_1 >= 0) {
            table[i][j] = ((table[i][j] >= table[i][idx_j_minus_1]) ? table[i][j] : table[i][idx_j_minus_1]);
        }
        int idx_i_plus_1 = i + 1;
        if (idx_i_plus_1 < n) {
            table[i][j] = ((table[i][j] >= table[idx_i_plus_1][j]) ? table[i][j] : table[idx_i_plus_1][j]);
        }
        if (idx_j_minus_1 >= 0 && idx_i_plus_1 < n) {
            int base_sum = (seq[i]) + (seq[j]);
            int match = (base_sum == 3) ? 1 : 0;
            if (i < j - 1) {
                table[i][j] = ((table[i][j] >= table[idx_i_plus_1][idx_j_minus_1] + match) ? table[i][j] : table[idx_i_plus_1][idx_j_minus_1] + match);
            } else {
                table[i][j] = ((table[i][j] >= table[idx_i_plus_1][idx_j_minus_1]) ? table[i][j] : table[idx_i_plus_1][idx_j_minus_1]);
            }
        }
        for (k = i + 1; k < j; k++) {
            table[i][j] = ((table[i][j] >= table[i][k] + table[k + 1][j]) ? table[i][j] : table[i][k] + table[k + 1][j]);
        }
    }
}
}
