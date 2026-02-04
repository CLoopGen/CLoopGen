#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int ar_order;
extern double *k;
extern double *r;
extern double *a;
extern double alpha;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
double temp_alpha = alpha;
for (i = 1; i < ar_order; i++) {
    double epsilon = r[i + 1];
    for (j = 0; j < i; j++) {
        epsilon += a[j] * r[i - j];
        a[j] = a[j]; // Introduce benign WAW dependency: write after write to a[j]
    }
    double ki_val = -epsilon / temp_alpha;
    k[i] = ki_val;
    temp_alpha *= (1. - ki_val * ki_val);
    for (j = i - 1; j >= 0; j--)
        k[j] = a[j] + ki_val * a[i - j - 1];
    // Reverse update order to change WAR dependencies
    for (j = i; j >= 0; j--)
        a[j] = k[j];
}
alpha = temp_alpha; // Update alpha once at the end (breaking loop-carried RAW/WAW on alpha)
}
