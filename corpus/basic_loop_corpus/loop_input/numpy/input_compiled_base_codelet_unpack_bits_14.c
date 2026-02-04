#include <stddef.h>
#include <stdlib.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;

npy_intp out_pad = 1048576; // 1MB / sizeof(char) -> 1M iterations ~0.01 sec
npy_intp out_stride = 1;
npy_intp _usr_index = 0;

char *outptr;

void init_vars() {
    outptr = (char *)calloc(out_pad, sizeof(char));
    if (!outptr) {
        exit(1);
    }
}