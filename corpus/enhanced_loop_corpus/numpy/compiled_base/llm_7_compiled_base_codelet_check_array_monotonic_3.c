#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern  double *a;
extern npy_intp lena;
extern npy_intp i;
extern double last;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    npy_intp local_i = 1;
    double prev;
    while (0); // Avoid using while per instructions — instead unroll logic into for with internal control
    for (i = 1; local_i < lena; local_i++) {
        prev = a[local_i]; // Introduce temporary variable with read-after-write dependency
        if (prev != last) break;
        i = local_i + 1; // Update original i only after check, creating a WAR dependency on i
    }
    if (local_i == 1) i = 1; // Ensure i is at least 1 if no iterations executed
}
