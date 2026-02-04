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
// Change memory access pattern to use strided access via pointer arithmetic with precomputed row offsets
for (i = n - 1; i >= 0; i--) {
    int *table_row_i = table[i];
    for (j = i + 1; j < n; j++) {
        if (j - 1 >= 0) {
            int *table_row_i_j_minus_1 = table[i] + (j - 1);
            table_row_i[j] = (table_row_i[j] >= *table_row_i_j_minus_1) ? table_row_i[j] : *table_row_i_j_minus_1;
        }
        if (i + 1 < n) {
            int *table_row_i_plus_1 = table[i + 1];
            table_row_i[j] = (table_row_i[j] >= table_row_i_plus_1[j]) ? table_row_i[j] : table_row_i_plus_1[j];
        }
        if (j - 1 >= 0 && i + 1 < n) {
            int *table_ref = table[i + 1] + (j - 1);
            int match = (((seq[i]) + (seq[j])) == 3) ? 1 : 0;
            if (i < j - 1) {
                table_row_i[j] = (table_row_i[j] >= (*table_ref + match)) ? table_row_i[j] : (*table_ref + match);
            } else {
                table_row_i[j] = (table_row_i[j] >= *table_ref) ? table_row_i[j] : *table_ref;
            }
        }
        for (k = i + 1; k < j; k++) {
            int *table_ik = table[i] + k;
            int *table_k1j = table[k + 1] + j;
            table_row_i[j] = (table_row_i[j] >= (*table_ik + *table_k1j)) ? table_row_i[j] : (*table_ik + *table_k1j);
        }
    }
}
}
