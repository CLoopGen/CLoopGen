#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

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
integer i__3;
integer i__;
integer j;
integer k;
doublereal temp;
logical nounit;

#define A_ROWS 1024
#define A_COLS 1024
#define B_ROWS 1024
#define B_COLS 512

static doublereal alpha_storage = 1.5;
static integer m_storage = B_ROWS;
static integer a_dim1_storage = A_ROWS;
static integer b_dim1_storage = B_ROWS;
static integer i__1_storage = B_COLS;
static doublereal *a_array = NULL;
static doublereal *b_array = NULL;

void init_vars() {
    a_dim1 = a_dim1_storage;
    b_dim1 = b_dim1_storage;
    m = &m_storage;
    alpha = &alpha_storage;
    a = a_array;
    b = b_array;
    i__1 = i__1_storage;
    nounit = 1;
    temp = 0.0;

    // Initialize arrays
    if (a_array == NULL) {
        a_array = (doublereal*)calloc(A_ROWS * A_COLS, sizeof(doublereal));
        for (int i = 0; i < A_ROWS * A_COLS; ++i) {
            a_array[i] = sin(i * 0.01);
        }
    }

    if (b_array == NULL) {
        b_array = (doublereal*)calloc(B_ROWS * B_COLS, sizeof(doublereal));
        for (int i = 0; i < B_ROWS; ++i) {
            for (int j = 0; j < B_COLS; ++j) {
                if ((i % 17) == 0) {
                    b_array[i + j * B_ROWS] = cos(i + j * 0.1);
                }
            }
        }
    }

    a = a_array;
    b = b_array;
}