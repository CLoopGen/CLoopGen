#include <stdlib.h>
#include <string.h>

typedef long BLASLONG;

BLASLONG bm = 1024;
BLASLONG bn = 512;
BLASLONG bk = 128;
float alpha = 1.1f;
float *ba;
float *bb;
float *C;
BLASLONG ldc = 1024;
BLASLONG i;
BLASLONG j;
BLASLONG k;
float *C0;
float *ptrba;
float *ptrbb;
float res0;
float res1;
float load0;
float load1;
float load2;
BLASLONG off = 0;
BLASLONG temp;

static void* allocate_aligned(size_t alignment, size_t size) {
    void* ptr;
#ifdef _POSIX_C_SOURCE
    if (posix_memalign(&ptr, alignment, size) != 0)
        ptr = NULL;
#else
    ptr = malloc(size);
    if (ptr && ((uintptr_t)ptr % alignment))
        ptr = (void*)(((char*)ptr) + alignment - ((uintptr_t)ptr % alignment));
#endif
    return ptr;
}

void init_vars() {
    int total_size_ba = bm * bk;
    int total_size_bb = bk * bn;
    int total_size_c = bm * ldc;

    float *raw_ba = (float*)allocate_aligned(32, sizeof(float) * total_size_ba);
    float *raw_bb = (float*)allocate_aligned(32, sizeof(float) * total_size_bb);
    float *raw_c  = (float*)allocate_aligned(32, sizeof(float) * total_size_c);

    ba = raw_ba;
    bb = raw_bb;
    C  = raw_c;

    for (int i = 0; i < total_size_ba; i++) raw_ba[i] = 1.0f;
    for (int i = 0; i < total_size_bb; i++) raw_bb[i] = 1.0f;
    for (int i = 0; i < total_size_c;  i++) raw_c[i]  = 0.0f;
}