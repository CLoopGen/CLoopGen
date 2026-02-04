#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef int integer;
typedef float real;
typedef int logical;

integer *m;
real *alpha;
real *a;
real *b;
integer a_dim1;
integer b_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;
integer k;
real temp;
logical nounit;

static real alpha_data;
static integer m_data;
static integer a_dim1_data;
static integer b_dim1_data;
static integer i__1_data;

#define A_ROWS 1000
#define A_COLS 1000
#define B_ROWS A_ROWS
#define B_COLS 50

static real *a_data_ptr = NULL;
static real *b_data_ptr = NULL;

void init_vars() {
    const double target_time = 0.01;
    const double est_ops_per_iter = 1000.0;
    const double est_cycles_per_op = 10.0;
    const double cpu_freq_ghz = 3.0;
    const double cycles_per_sec = cpu_freq_ghz * 1e9;
    const double total_ops = target_time * cycles_per_sec / est_cycles_per_op;

    i__1_data = (integer)ceil(sqrt(total_ops / est_ops_per_iter));
    if (i__1_data < 10) i__1_data = 10;
    if (i__1_data > B_COLS) i__1_data = B_COLS;

    m_data = A_ROWS;
    a_dim1_data = A_ROWS;
    b_dim1_data = B_ROWS;

    m = &m_data;
    alpha = &alpha_data;
    a = a_data_ptr;
    b = b_data_ptr;
    a_dim1 = a_dim1_data;
    b_dim1 = b_dim1_data;
    i__1 = i__1_data;
    nounit = 1;
    alpha_data = 1.01f;

    srand(12345);
    for (int i = 1; i <= A_ROWS; ++i) {
        for (int j = 1; j <= A_COLS; ++j) {
            a_data_ptr[i + j * a_dim1] = rand() / (real)RAND_MAX;
        }
    }

    for (int i = 1; i <= B_ROWS; ++i) {
        for (int j = 1; j <= B_COLS; ++j) {
            b_data_ptr[i + j * b_dim1] = rand() / (real)RAND_MAX;
        }
    }
}

static void allocate_arrays() {
    const size_t a_size = (A_ROWS + 1) * (A_COLS + 1) * sizeof(real);
    const size_t b_size = (B_ROWS + 1) * (B_COLS + 1) * sizeof(real);

    a_data_ptr = (real*)calloc(a_size, 1);
    b_data_ptr = (real*)calloc(b_size, 1);

    if (!a_data_ptr || !b_data_ptr) {
        exit(1);
    }
}

__attribute__((constructor))
static void constructor() {
    allocate_arrays();
    init_vars();
}