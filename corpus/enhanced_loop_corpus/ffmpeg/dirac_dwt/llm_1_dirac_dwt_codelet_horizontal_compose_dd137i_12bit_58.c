#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int w2;
extern int x;
extern int32_t *b;
extern int32_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < w2; outer += 2) { // Decreased effective depth by unrolling and reducing iterations
        for (int inner = 0; inner < 2 && (outer + inner) < w2; inner++) {
            int x = outer + inner;
            b[2 * x] = ((int)(tmp[x] + 1U)) >> 1;
            b[2 * x + 1] = ((int)((int)(((unsigned int)(b[x + w2]) + ((int)(9U * tmp[x] + 9U * tmp[x + 1] - tmp[x + 2] - tmp[x - 1] + 8) >> 4))) + 1U)) >> 1;
        }
    }
}
