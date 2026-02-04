#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef int int32;
typedef unsigned short uint16;

int32 n_el;
int32 i;
uint16 *buf16;

void init_vars() {
    // Estimate data size for ~0.01s runtime: assume simple shift/or operation on 1M to 256M elements
    // Choose 8M uint16 elements = 16 MB of data, typical for small L2/L3 cache pressure and measurable time
    n_el = 8000000;

    // Allocate buffer
    buf16 = (uint16*)aligned_alloc(32, n_el * sizeof(uint16));
    
    // Initialize buffer with non-zero pattern to make transformation observable
    for (int32 idx = 0; idx < n_el; idx++) {
        buf16[idx] = (uint16)(idx & 0xFFFF);
    }
}