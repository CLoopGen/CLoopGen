#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *i0;
extern real *z__;
extern integer i__1;
extern integer j4;
extern integer ipn4;
extern real temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    integer j4_inner;
    for (j4 = *i0 << 2; j4 <= i__1; j4 += 4) {
        for (j4_inner = j4; j4_inner < j4 + 4; ++j4_inner) {
            if (j4_inner == j4 - 3 + 3) {
                temp = z__[j4_inner];
                z__[j4_inner] = z__[ipn4 - j4_inner - 4];
                z__[ipn4 - j4_inner - 4] = temp;
            } else if (j4_inner == j4 - 2 + 2) {
                temp = z__[j4_inner];
                z__[j4_inner] = z__[ipn4 - j4_inner - 2];
                z__[ipn4 - j4_inner - 2] = temp;
            } else if (j4_inner == j4 - 1 + 1) {
                temp = z__[j4_inner];
                z__[j4_inner] = z__[ipn4 - j4_inner - 5];
                z__[ipn4 - j4_inner - 5] = temp;
            } else if (j4_inner == j4) {
                temp = z__[j4_inner];
                z__[j4_inner] = z__[ipn4 - j4_inner - 4];
                z__[ipn4 - j4_inner - 4] = temp;
            }
        }
    }
}
