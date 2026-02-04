#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short IDWTELEM;

extern int i;
extern IDWTELEM *dst;
extern IDWTELEM *src;
extern IDWTELEM *ref;
extern int w;
extern int mul;
extern int add;
extern int shift;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive pair-wise access using pointer arithmetic
    IDWTELEM *d = dst + i;
    IDWTELEM *s = src + i;
    IDWTELEM *r = ref + i;
    int remaining = w - i;

    for (int j = 0; j < remaining; j++) {
        d[j] = s[j] - ((mul * (r[j] + r[j + 1]) + add) >> shift);
    }
}
