#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern npy_intp cnt;
extern npy_intp i;
extern int bcnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    npy_intp outer;
    npy_intp step = 16;
    for (outer = 0; outer < cnt; outer += step) {
        for (i = outer; i < cnt && i < outer + step; i++) {
            if (!bcnt) {
                bcnt = 31;
            } else {
                bcnt--;
            }
        }
    }
}
