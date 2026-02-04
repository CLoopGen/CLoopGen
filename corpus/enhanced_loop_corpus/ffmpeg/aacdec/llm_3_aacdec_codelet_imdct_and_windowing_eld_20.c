#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float INTFLOAT;

extern INTFLOAT *out;
extern INTFLOAT *saved;
extern INTFLOAT *buf;
extern int i;
extern  int n;
extern  int n2;
extern  int n4;
extern  INTFLOAT * window;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive forward indexing with pointer arithmetic
    // Arrays are accessed using pointers incremented consecutively to promote cache locality and pipelining
    INTFLOAT *p_out = out;
    INTFLOAT *p_buf = buf + n2 - 1 - n4;
    INTFLOAT *p_saved1 = saved + n2 + n4;
    INTFLOAT *p_saved2 = saved + n + n2 - 1 - n4;
    INTFLOAT *p_saved3 = saved + 2 * n + n2 + n4;
    INTFLOAT *p_win1 = window;
    INTFLOAT *p_win2 = window + n;
    INTFLOAT *p_win3 = window + 2 * n;
    INTFLOAT *p_win4 = window + 3 * n;

    int count = n2 - n4;
    for (int j = 0; j < count; j++) {
        p_out[j] = 
            (p_buf[-j] * p_win1[j]) +
            (p_saved1[j] * p_win2[j]) +
            (-p_saved2[-j] * p_win3[j]) +
            (-p_saved3[j] * p_win4[j]);
    }
}
