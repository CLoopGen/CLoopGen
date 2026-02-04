#include <stdio.h>

int nrows = 1048576; // 1MB of integers (approx 4MB data)
int j;

int *rowstr_ptr;
int rowstr_buffer[1048576 + 2]; // Account for index up to nrows+1
int *rowstr = rowstr_buffer + 1; // rowstr[1] maps to buffer[1], allows rowstr[nrows+1]

void init_vars() {
    for (int i = 1; i <= nrows; i++) {
        rowstr[i] = i;
    }
}