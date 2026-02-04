#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short IDWTELEM;

typedef int x86_reg;

extern IDWTELEM *b;
extern  int w_r;
extern int i;
extern IDWTELEM * dst;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (; (((x86_reg)&dst[i]) & 31) && i < w_r; i++) {
    dst[i] = dst[i] - (b[i] + b[i + 1]);
}

}
