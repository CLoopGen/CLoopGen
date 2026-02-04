#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ni;
extern int *left;
extern int *right;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (i = 1; i < ni; ++i) {
        int *l_ptr = &left[i];
        int *r_ptr = &right[i];
        int local_jj_start = *l_ptr;
        int local_jj_end = *r_ptr;
        for (int jj = local_jj_start; jj <= local_jj_end; ++jj) {
            j++;
        }
    }
}
