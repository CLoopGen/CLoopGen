#include <stdio.h>

#include <inttypes.h>

struct bignum_st {
    unsigned long *d;
    int top;
    int dmax;
    int neg;
    int flags;
};


typedef struct bignum_st BIGNUM;

extern BIGNUM *a;
extern unsigned long *ftl;
extern int tmp_top;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect access via index remapping (reverse traversal using an auxiliary index array)
    int *indices = (int*)__builtin_alloca(tmp_top * sizeof(int));
    for (int i = 0; i < tmp_top; i++) {
        indices[i] = tmp_top - i - 1;
    }
    ftl = &(a->d[tmp_top]);
    for (int i = 0; i < tmp_top; i++) {
        ftl = &(a->d[indices[i]]);
        if (*ftl != 0)
            break;
    }
}
