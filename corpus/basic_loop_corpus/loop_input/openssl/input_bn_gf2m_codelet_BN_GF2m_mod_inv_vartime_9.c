#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

int i;
int top;
unsigned long *udp;
unsigned long *bdp;
unsigned long *vdp;
unsigned long *cdp;

static unsigned long *alloc_aligned_array(int size) {
    void *ptr;
    if (posix_memalign(&ptr, 32, size * sizeof(unsigned long)) != 0) {
        exit(1);
    }
    return (unsigned long *)ptr;
}

void init_vars() {
    const int data_size_kb = 512;
    const int num_elements = (data_size_kb * 1024) / sizeof(unsigned long);

    top = num_elements;

    udp = alloc_aligned_array(top);
    bdp = alloc_aligned_array(top);
    vdp = alloc_aligned_array(top);
    cdp = alloc_aligned_array(top);

    for (int idx = 0; idx < top; idx++) {
        udp[idx] = (unsigned long)(idx * 37);
        bdp[idx] = (unsigned long)(idx * 73);
        vdp[idx] = (unsigned long)(idx * 17);
        cdp[idx] = (unsigned long)(idx * 29);
    }
}