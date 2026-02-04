#include <stdio.h>
#include <inttypes.h>

int n = 1000;
double x1[2000];
double x2[2000];
double y_1[2000];
double y_2[2000];
double A[2000][2000];
int i;
int j;

void init_vars() {
    // Ensure n does not exceed array bounds
    if (n > 2000) {
        n = 2000;
    }
}