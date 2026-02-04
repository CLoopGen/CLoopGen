#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *top;
extern int16_t *bottom;
extern int i;
extern int a;
extern int b;
extern int c;
extern int d;
extern int d1;
extern int d2;
extern int rnd1;
extern int rnd2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int16_t *t_indices[8] = {&top[48], &top[56], &top[48], &top[56], &top[48], &top[56], &top[48], &top[56]};
int16_t *b_indices[8] = {&bottom[0], &bottom[8], &bottom[0], &bottom[8], &bottom[0], &bottom[8], &bottom[0], &bottom[8]};
for (i = 0; i < 8; i++) {
    a = *(t_indices[i]);
    b = *(t_indices[i] + 8);
    c = *(b_indices[i]);
    d = *(b_indices[i] + 8);
    d1 = a - d;
    d2 = a - d + b - c;
    *(t_indices[i]) = ((a << 3) - d1 + rnd1) >> 3;
    *(t_indices[i] + 8) = ((b << 3) - d2 + rnd2) >> 3;
    *(b_indices[i]) = ((c << 3) + d2 + rnd1) >> 3;
    *(b_indices[i] + 8) = ((d << 3) + d1 + rnd2) >> 3;
    rnd2 = 7 - rnd2;
    rnd1 = 7 - rnd1;
}
}
