#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/time.h>

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

static real *a_data = NULL;
static integer m_val, n_val;

void init_vars() {
    struct timeval start, end;
    gettimeofday(&start, NULL);

    n_val = 500; 
    m_val = 500;  
    i__1 = n_val;
    a_dim1 = n_val;
    *m = m_val;
    mul = 1.5f;

    size_t size = (size_t)(m_val + 1) * (n_val + 1);
    a_data = (real*)calloc(size, sizeof(real));
    if (!a_data) {
        exit(1);
    }
    a = a_data - 1 - a_dim1;  

    for (j = 1; j <= i__1; ++j) {
        i__2 = *m;
        for (i__ = 1; i__ <= i__2; ++i__) {
            a[i__ + j * a_dim1] = 1.0f;
        }
    }

    gettimeofday(&end, NULL);
    double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1e6;

    while (elapsed < 0.01) {
        n_val += 50;
        m_val += 50;
        i__1 = n_val;
        *m = m_val;
        a_dim1 = n_val;

        size = (size_t)(m_val + 1) * (n_val + 1);
        free(a_data);
        a_data = (real*)calloc(size, sizeof(real));
        if (!a_data) {
            exit(1);
        }
        a = a_data - 1 - a_dim1;

        gettimeofday(&start, NULL);
        for (j = 1; j <= i__1; ++j) {
            i__2 = *m;
            for (i__ = 1; i__ <= i__2; ++i__) {
                a[i__ + j * a_dim1] = 1.0f;
            }
        }
        gettimeofday(&end, NULL);
        elapsed = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1e6;
    }

    for (j = 1; j <= i__1; ++j) {
        i__2 = *m;
        for (i__ = 1; i__ <= i__2; ++i__) {
            a[i__ + j * a_dim1] = 1.0f + (i__ % 100) * 0.01f;
        }
    }
}

integer* m = &m_val;