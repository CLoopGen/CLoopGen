#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int *ptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int indices[8] = {0, 1, 2, 3, 4, 5, 6, 7};
for (i = 0; i < 8; i++) {
    const unsigned int t0 = -39409U * ptr[indices[7]] - 58980U * ptr[indices[1]];
    const unsigned int t1 = 39410U * ptr[indices[1]] - 58980U * ptr[indices[7]];
    const unsigned int t2 = -33410U * ptr[indices[5]] - 167963U * ptr[indices[3]];
    const unsigned int t3 = 33410U * ptr[indices[3]] - 167963U * ptr[indices[5]];
    const unsigned int t4 = ptr[indices[3]] + ptr[indices[7]];
    const unsigned int t5 = ptr[indices[1]] + ptr[indices[5]];
    const unsigned int t6 = 77062U * t4 + 51491U * t5;
    const unsigned int t7 = 77062U * t5 - 51491U * t4;
    const unsigned int t8 = 35470U * ptr[indices[2]] - 85623U * ptr[indices[6]];
    const unsigned int t9 = 35470U * ptr[indices[6]] + 85623U * ptr[indices[2]];
    const unsigned int tA = (((ptr[indices[0]] - ptr[indices[4]]) * (1U << 16)) + 8192);
    const unsigned int tB = (((ptr[indices[0]] + ptr[indices[4]]) * (1U << 16)) + 8192);
    ptr[indices[0]] = (int)(t1 + t6 + t9 + tB) >> 13;
    ptr[indices[1]] = (int)(t3 + t7 + t8 + tA) >> 13;
    ptr[indices[2]] = (int)(t2 + t6 - t8 + tA) >> 13;
    ptr[indices[3]] = (int)(t0 + t7 - t9 + tB) >> 13;
    ptr[indices[4]] = (int)(-(t0 + t7) - t9 + tB) >> 13;
    ptr[indices[5]] = (int)(-(t2 + t6) - t8 + tA) >> 13;
    ptr[indices[6]] = (int)(-(t3 + t7) + t8 + tA) >> 13;
    ptr[indices[7]] = (int)(-(t1 + t6) + t9 + tB) >> 13;
    ;
    ptr += 8;
}
}
