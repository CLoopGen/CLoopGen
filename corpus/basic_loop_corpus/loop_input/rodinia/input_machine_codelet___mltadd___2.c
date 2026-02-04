#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double *dp1;
double *dp2;
double s;
int i;
int len4;

void init_vars() {
    const size_t total_size = 64 * 1024 * 1024; // ~64 MB of data for dp1 and dp2
    const size_t num_doubles = total_size / sizeof(double) / 8; // Each array uses 4*i stride, so we use 8 per iteration
    len4 = (int)(num_doubles / 4); // Each loop iteration accesses 4 elements

    double *data1 = calloc(total_size, 1);
    double *data2 = calloc(total_size, 1);
    if (!data1 || !data2) {
        exit(1);
    }

    dp1 = data1;
    dp2 = data2;
    s = 1.5;

    // Ensure that dp1[4*i + 3] is within bounds at maximum i
    // So we require: 4*(len4-1)+3 < num_doubles => 4*len4 -1 < num_doubles
    // Our len4 is chosen safely based on allocation.
}

// Separate function to force compiler to not optimize away pointers
void __attribute__((noinline)) touch(double *p) {
    if (p) p[0] += 0.0;
}

void loop(); // forward declaration

// Example usage in another file:
// int main() { init_vars(); loop(); touch(dp1); return 0; }