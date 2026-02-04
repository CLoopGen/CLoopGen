#include <stddef.h>
#include <stdlib.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;

npy_intp is0;
npy_intp is1;
npy_intp os;
npy_intp n;
char *i0;
char *i1;
char *o;
int k;

static char *i0_base;
static char *i1_base;
static char *o_base;
static size_t total_size;

void init_vars() {
    // Aim for ~64MB of data to ensure loop takes ~0.01s on modern CPUs
    total_size = 64 * 1024 * 1024;
    
    // Allocate input and output buffers
    i0_base = (char *)aligned_alloc(64, total_size);
    i1_base = (char *)aligned_alloc(64, total_size);
    o_base = (char *)aligned_alloc(64, total_size);
    
    if (!i0_base || !i1_base || !o_base) {
        exit(1);
    }
    
    // Initialize buffer contents
    for (size_t i = 0; i < total_size; i++) {
        i0_base[i] = (char)(i & 0xFF);
        i1_base[i] = (char)((i >> 8) & 0xFF);
        o_base[i] = 0;
    }
    
    // Set initial pointers
    i0 = i0_base;
    i1 = i1_base;
    o = o_base;
    
    // Set strides: assume unit stride per element
    is0 = 1;
    is1 = 1;
    os = 1;
    
    // Set loop count: ensures we traverse entire buffer without overflow
    n = total_size;
    
    // Reset loop counter
    k = 0;
}