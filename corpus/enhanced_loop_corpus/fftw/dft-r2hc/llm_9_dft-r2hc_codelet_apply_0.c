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
for (i = 2; i < (n + 1) / 2; i += 2) {
    E rop1, iop1, iom1, rom1;
    E rop2, iop2, iom2, rom2;
    rop1 = ro[os * i];
    iop1 = io[os * i];
    rom1 = ro[os * (n - i)];
    iom1 = io[os * (n - i)];
    rop2 = ro[os * (i - 1)];
    iop2 = io[os * (i - 1)];
    rom2 = ro[os * (n - i + 1)];
    iom2 = io[os * (n - i + 1)];
    ro[os * i] = rop1 - iom1;
    io[os * i] = iop1 + rom1;
    ro[os * (n - i)] = rop1 + iom1;
    io[os * (n - i)] = iop1 - rom1;
    ro[os * (i - 1)] = rop2 - iom2;
    io[os * (i - 1)] = iop2 + rom2;
    ro[os * (n - i + 1)] = rop2 + iom2;
    io[os * (n - i + 1)] = iop2 - rom2;
}
}
