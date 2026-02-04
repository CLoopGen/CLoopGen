#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/time.h>

typedef float UINTFLOAT;
typedef float INTFLOAT;

UINTFLOAT *in;
int i;
int n;
int n2;

static UINTFLOAT in_buffer[67108864]; // ~256 MB buffer (67M elements)

void init_vars() {
    n = 67108864; // Size of the array
    n2 = n / 2;   // Process half of the array in steps of 2

    // Ensure n2 is even to satisfy loop increment condition
    n2 = (n2 / 2) * 2;

    in = in_buffer;

    // Initialize input data to avoid undefined behavior
    for (int idx = 0; idx < n; ++idx) {
        in[idx] = (UINTFLOAT)(idx % 1000) / 10.0f;
    }
}