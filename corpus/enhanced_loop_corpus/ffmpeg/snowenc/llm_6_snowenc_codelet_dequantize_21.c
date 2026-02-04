#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short IDWTELEM;

extern IDWTELEM *src;
extern int stride;
extern  int w;
extern  int h;
extern  int qmul;
extern  int qadd;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    IDWTELEM *local_src = src;
    int local_stride = stride;
    int local_w = w;
    int local_h = h;
    int local_qmul = qmul;
    int local_qadd = qadd;
    int shift = 7 - 4 + 8;

    for (y = 0; y < local_h; y++) {
        int base_idx = y * local_stride;
        for (x = 0; x < local_w; x++) {
            int idx = base_idx + x;
            int i = local_src[idx];
            int temp_val = 0;
            if (i < 0) {
                temp_val = -((-i * local_qmul + local_qadd) >> shift);
            } else if (i > 0) {
                temp_val = (i * local_qmul + local_qadd) >> shift;
            }
            local_src[idx] = temp_val;
        }
    }
}
