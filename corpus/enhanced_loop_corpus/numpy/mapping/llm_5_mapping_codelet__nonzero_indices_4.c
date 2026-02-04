#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

typedef unsigned char npy_bool;

extern int nd;
extern int j;
extern npy_intp size;
extern npy_intp i;
extern npy_bool *ptr;
extern npy_intp coords[64];
extern npy_intp dims_m1[64];
extern npy_intp *dptr[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < size; i++) {
        npy_bool active = *(ptr++);
        j = 0;
        while_cond: ;
        if (!active || j >= nd) goto skip_write;
        *(dptr[j]++) = coords[j];
        j++;
        if (j < nd) goto while_cond;
skip_write:
        j = nd - 1;
        coord_loop: ;
        if (j < 0) goto loop_end;
        if (coords[j] < dims_m1[j]) {
            coords[j]++;
            goto loop_end;
        } else {
            coords[j] = 0;
            j--;
            goto coord_loop;
        }
loop_end: ;
    }
}
