#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t nz;
int *Aj;
int *ATp;
size_t i;

void init_vars() {
    nz = 64 * 1024 * 1024 / sizeof(int);  // ~256MB of input data (two int arrays)
    
    Aj = (int*)calloc(nz, sizeof(int));
    ATp = (int*)calloc(nz, sizeof(int));
    
    if (!Aj || !ATp) {
        exit(1);
    }
    
    for (size_t idx = 0; idx < nz; ++idx) {
        Aj[idx] = rand() % nz;
    }
}