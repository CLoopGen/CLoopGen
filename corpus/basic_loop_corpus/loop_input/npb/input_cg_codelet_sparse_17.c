#include <stdio.h>

typedef int boolean;

double a[1000000];
int colidx[1000000];
int rowstr[10000];
double x[10000];
boolean mark[10000];
int nzloc[10000];
int nrows = 9998;
int i;
int j;
int jajp1 = 0;
int nza = 0;
int k;
int nzrow;
double xi;

void init_vars() {
    int size = 1000000;
    int rows = 9998;

    nrows = rows;
    jajp1 = 0;
    nza = 0;

    for (int idx = 0; idx < size; idx++) {
        a[idx] = 1.0;
        colidx[idx] = (idx % (rows - 1)) + 1;
    }

    rowstr[1] = 0;
    int step = size / (rows + 1);
    for (int r = 2; r <= rows + 1; r++) {
        rowstr[r] = step * (r - 1);
    }
    rowstr[rows + 1] = size - 1;

    for (int idx = 1; idx <= rows; idx++) {
        x[idx] = 0.0;
        mark[idx] = 0;
    }
}