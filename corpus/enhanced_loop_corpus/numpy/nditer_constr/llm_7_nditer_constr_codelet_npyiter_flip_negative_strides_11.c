#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern npy_intp istrides;
extern npy_intp nstrides;
extern npy_intp *baseoffsets;
extern char **resetdataptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char **local_resetptr = resetdataptr;
    npy_intp *local_baseoffs = baseoffsets;
    for (istrides = 0; istrides < nstrides; ++istrides) {
        local_resetptr[istrides] += local_baseoffs[istrides];
        local_baseoffs[istrides] = 0; // Introduce WAW dependency by writing back
    }
}
