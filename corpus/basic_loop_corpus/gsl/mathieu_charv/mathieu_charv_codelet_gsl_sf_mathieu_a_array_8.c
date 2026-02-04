#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double qq;
extern unsigned int even_order;
extern unsigned int ii;
extern double *tt;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (ii = 1; ii < even_order - 1; ii++) {
    tt[3 * ii] = qq;
    tt[3 * ii + 1] = 4 * ii * ii;
    tt[3 * ii + 2] = qq;
}

}
