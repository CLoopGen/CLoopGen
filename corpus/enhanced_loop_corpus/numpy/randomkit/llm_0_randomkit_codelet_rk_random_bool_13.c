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
    npy_intp j;
    for (i = 0; i < cnt; i++) {
        for (j = 0; j < 32; j++) {
            if (j == bcnt) {
                bcnt = 31;
            } else {
                bcnt--;
                break;
            }
        }
    }
}
