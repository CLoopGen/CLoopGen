#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef int integer;
typedef double doublereal;

integer *n;
doublereal *alpha;
doublereal *x;
doublereal *y;
doublereal *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;
doublereal temp1;
doublereal temp2;

#define DATA_SIZE 2048

static doublereal alpha_data = 1.5;
static integer n_data = DATA_SIZE;
static integer i__1_data = DATA_SIZE;
static integer a_dim1_data = DATA_SIZE;

static doublereal *x_data;
static doublereal *y_data;
static doublereal *a_data;

void init_vars() {
    x_data = (doublereal*)calloc(DATA_SIZE + 1, sizeof(doublereal));
    y_data = (doublereal*)calloc(DATA_SIZE + 1, sizeof(doublereal));
    a_data = (doublereal*)calloc((DATA_SIZE + 1) * (DATA_SIZE + 1), sizeof(doublereal));

    if (!x_data || !y_data || !a_data) {
        exit(1);
    }

    for (int idx = 1; idx <= DATA_SIZE; ++idx) {
        x_data[idx] = sin(idx);
        y_data[idx] = cos(idx);
    }

    for (int row = 1; row <= DATA_SIZE; ++row) {
        for (int col = 1; col <= DATA_SIZE; ++col) {
            a_data[row + col * DATA_SIZE] = 0.0;
        }
    }

    n = &n_data;
    alpha = &alpha_data;
    x = x_data;
    y = y_data;
    a = a_data;
    a_dim1 = a_dim1_data;
    i__1 = i__1_data;
}