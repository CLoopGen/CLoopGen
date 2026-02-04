#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double R;

typedef ptrdiff_t INT;

typedef R E;

extern R *ro;
extern R *io;
extern INT n;
extern INT i;
extern INT os;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic
    // Instead of indexing with stride 'os', we step through memory consecutively using pointers
    // Assumes that the effective data is laid out such that strided access can be unrolled into consecutive accesses
    E *ro_ptr = ro + os;
    E *io_ptr = io + os;
    E *ro_rev = ro + os * (n - 1);
    E *io_rev = io + os * (n - 1);
    
    for (i = 1; i < (n + 1) / 2; ++i) {
        E rop = *ro_ptr;
        E iop = *io_ptr;
        E rom = *ro_rev;
        E iom = *io_rev;

        *ro_ptr = rop - iom;
        *io_ptr = iop + rom;
        *ro_rev = rop + iom;
        *io_rev = iop - rom;

        ro_ptr += os;
        io_ptr += os;
        ro_rev -= os;
        io_rev -= os;
    }
}
