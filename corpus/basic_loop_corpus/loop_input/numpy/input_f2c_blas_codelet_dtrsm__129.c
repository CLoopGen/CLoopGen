#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef double doublereal;
typedef int logical;

integer *m;
doublereal *alpha;
doublereal *a;
doublereal *b;
integer a_dim1;
integer b_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;
integer k;
logical nounit;

static doublereal alpha_storage;
static integer m_storage;
static integer a_dim1_storage;
static integer b_dim1_storage;
static integer i__1_storage;

#define A_SIZE 8192
#define B_SIZE 8192

static doublereal a_storage[A_SIZE];
static doublereal b_storage[B_SIZE];

void init_vars() {
    m = &m_storage;
    alpha = &alpha_storage;
    a = a_storage;
    b = b_storage;
    a_dim1 = a_dim1_storage;
    b_dim1 = b_dim1_storage;
    i__1 = i__1_storage;
    nounit = 1;

    m_storage = 64;
    a_dim1_storage = 64;
    b_dim1_storage = 64;
    i__1_storage = 64;
    alpha_storage = 1.5;

    const integer size_a = m_storage * m_storage;
    const integer size_b = m_storage * i__1_storage;

    for (integer idx = 0; idx < size_a; ++idx) {
        a_storage[idx] = 1.0 + 0.01 * idx;
    }

    for (integer idx = 0; idx < size_b; ++idx) {
        b_storage[idx] = 2.0 + 0.01 * idx;
    }

    for (integer j = 1; j <= i__1_storage; ++j) {
        for (integer k = m_storage; k >= 1; --k) {
            if (k <= m_storage && j <= b_dim1_storage) {
                integer b_idx = k - 1 + (j - 1) * b_dim1_storage;
                if (b_idx >= 0 && b_idx < B_SIZE) {
                    b_storage[b_idx] = (k == j) ? 1.0 : (k > j ? 0.5 : 0.3);
                }
            }
        }
    }

    for (integer k = 1; k <= m_storage; ++k) {
        integer a_idx = (k - 1) + (k - 1) * a_dim1_storage;
        if (a_idx >= 0 && a_idx < A_SIZE) {
            a_storage[a_idx] = 2.0;
        }
    }
}