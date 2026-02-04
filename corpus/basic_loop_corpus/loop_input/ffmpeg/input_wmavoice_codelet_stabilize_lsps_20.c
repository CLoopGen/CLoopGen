#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double *lsps;
int num;
int n;
int m;
int l;

void init_vars() {
    num = 65536; // Size chosen to achieve ~0.01 sec runtime on modern CPU
    lsps = (double*)aligned_alloc(32, num * sizeof(double));
    if (!lsps) exit(1);

    // Initialize with descending order to trigger worst-case sorting behavior
    for (int i = 0; i < num; i++) {
        lsps[i] = (double)(num - i);
    }

    // Ensure first violation occurs at n=1: lsps[1] < lsps[0]
    // Already satisfied by descending initialization

    n = 0;
    m = 0;
    l = 0;
}