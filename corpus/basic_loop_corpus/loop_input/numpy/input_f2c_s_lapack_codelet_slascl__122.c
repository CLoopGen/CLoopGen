#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef int integer;
typedef float real;

integer *m;
real *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;
real mul;

real *a_data;
integer m_val;

void init_vars() {
    const int target_time_ms = 10;
    double elapsed = 0.0;
    clock_t start, end;

    int base_size = 1000;
    int size;

    while (elapsed < target_time_ms * CLOCKS_PER_SEC / 1000.0) {
        base_size *= 2;
        size = base_size;

        if (a_data) free(a_data);
        if (m) free(m);

        a_data = (real*)calloc(size * size, sizeof(real));
        m = (integer*)malloc(sizeof(integer));
        if (!a_data || !m) {
            perror("allocation failed");
            exit(1);
        }

        *m = size;
        a = a_data - 1 - size; 
        a_dim1 = size;
        i__1 = size;
        mul = 1.5f;

        start = clock();
        for (j = 1; j <= i__1; ++j) {
            i__2 = (j < *m) ? j : *m;
            for (i__ = 1; i__ <= i__2; ++i__) {
                a[i__ + j * a_dim1] += 1.0f;
            }
        }
        end = clock();
        elapsed = (double)(end - start);

        if (elapsed >= target_time_ms * CLOCKS_PER_SEC / 1000.0) break;
    }

    for (int idx = 0; idx < size * size; ++idx) {
        a_data[idx] = 1.0f;
    }

    m_val = size;
    *m = m_val;
}