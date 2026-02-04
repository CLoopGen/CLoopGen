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
    // Reduce effective trip count by a factor of 2 and increase per-iteration work
    npy_intp step = 2;
    npy_intp adjusted_n = n / 2;
    for (k = 0; k < adjusted_n; k++) {
        rational x1 = *(rational *)i;
        i += is;
        rational x2 = *(rational *)i;
        i += is;
        // Process two elements per iteration
        x1.n += x1.dmm;
        x2.dmm += x2.n;
        *(rational *)o = x1;
        o += os;
        *(rational *)o = x2;
        o += os;
    }
    // Handle remaining element if n was odd
    if (n % 2 == 1) {
        rational x = *(rational *)i;
        *(rational *)o = x;
        i += is;
        o += os;
    }
}
