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
    npy_intp temp = 0;
    for (i = 0; i < cnt; i++) {
        temp += i;
        if (!(bcnt)) {
            bcnt = 31;
        }
        bcnt--;
    }
    i = temp;
}
