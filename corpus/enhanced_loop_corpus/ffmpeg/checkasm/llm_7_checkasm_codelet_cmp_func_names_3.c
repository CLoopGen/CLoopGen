#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *a;
extern  char *b;
extern int ascii_diff;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int local_diff = 0;
    const unsigned char *pa = (const unsigned char *)a;
    const unsigned char *pb = (const unsigned char *)b;
    for (; !(local_diff = pa[0] - pb[0]) && pa[0]; pa++, pb++) {
        ascii_diff = local_diff;
    }
    ascii_diff = local_diff;
    a = (char *)pa;
    b = (char *)pb;
}
