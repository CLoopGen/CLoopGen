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
    for (INT j = 1; j <= 1; ++j) {
        for (i = 1; i < (n + 1) / 2; ++i) {
            E rop, iop, iom, rom;
            rop = ro[os * i];
            iop = io[os * i];
            rom = ro[os * (n - i)];
            iom = io[os * (n - i)];
            ro[os * i] = rop - iom;
            io[os * i] = iop + rom;
            ro[os * (n - i)] = rop + iom;
            io[os * (n - i)] = iop - rom;
        }
    }
}
