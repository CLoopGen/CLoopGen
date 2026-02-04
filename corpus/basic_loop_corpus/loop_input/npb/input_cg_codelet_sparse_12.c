#include <stdio.h>

int nrows = 1048576;  // Approximately 2^20 elements for ~1MB-256MB data size
int j;
int *rowstr_ptr;
int rowstr[1048578];  // Size = nrows + 2 to accommodate indices from 0 to nrows+1

void init_vars() {
    rowstr_ptr = rowstr;
    for (int i = 0; i <= nrows + 1; i++) {
        rowstr[i] = i;  // Initialize with non-zero values for meaningful computation
    }
}