#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

typedef struct {
    int n;
    int dmm;
} rational;

extern npy_intp is;
extern npy_intp os;
extern npy_intp n;
extern char *i;
extern char *o;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    npy_intp outer_k;
    for (outer_k = 0; outer_k < n; outer_k++) {
        k = outer_k;
        {
            rational x = *(rational *)i;
            i += is;
            o += os;
        }
    }
}
