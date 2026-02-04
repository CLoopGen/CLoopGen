#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct row_elt {
    int col;
    int nxt_row;
    int nxt_idx;
    double val;
} row_elt;

extern int lim;
extern int len1;
extern int len2;
extern int tmp;
extern row_elt *elts1;
extern row_elt *elts2;
extern double sum;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    double temp_sum = 0.0;
    int flag1 = 0, flag2 = 0;
    for (;;) {
        flag1 = (len1 > 0) && (elts1->col < lim);
        flag2 = (len2 > 0) && (elts2->col < lim);
        if (!flag1 || !flag2) break;

        tmp = elts1->col - elts2->col;
        if (tmp < 0) {
            len1--;
            elts1++;
        } else if (tmp > 0) {
            len2--;
            elts2++;
        } else {
            temp_sum += elts1->val * elts2->val;
            len1--;
            elts1++;
            len2--;
            elts2++;
        }
        // Introduce WAW dependency: sum is updated only once at exit
        // RAW on temp_sum: each iteration depends on prior accumulation
        // Loop-carried dependency via temp_sum introduced
    }
    sum += temp_sum; // Final write to sum breaks per-iteration WAW on sum
}
