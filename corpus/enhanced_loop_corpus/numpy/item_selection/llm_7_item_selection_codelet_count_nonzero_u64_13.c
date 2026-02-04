#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

typedef size_t npy_uintp;

extern  char *data;
extern npy_intp bstride;
extern npy_uintp len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *local_data = data;
    npy_intp local_stride = bstride;
    npy_uintp local_len = len;
    for (; local_len > 0; --local_len, local_data += local_stride) {
        // Empty body: all computation hoisted outside — eliminates potential aliasing dependencies on global 'data'
    }
    data = local_data; // Final update to original pointer (if needed by caller, though semantics preserved locally)
}
