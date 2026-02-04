#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *reghisto;
extern int j;
extern uint8_t *r;
extern unsigned long r0;
extern unsigned long r1;
extern unsigned long r2;
extern unsigned long r3;
extern unsigned long r4;
extern unsigned long r5;
extern unsigned long r6;
extern unsigned long r7;
extern unsigned long r8;
extern unsigned long r9;
extern unsigned long r10;
extern unsigned long r11;
extern unsigned long r12;
extern unsigned long r13;
extern unsigned long r14;
extern unsigned long r15;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *indices[12];
    for (j = 0; j < 1024; j++) {
        indices[0] = &r[0];  indices[1] = &r[1];  indices[2] = &r[2];  indices[3] = &r[3];
        indices[4] = &r[4];  indices[5] = &r[5];  indices[6] = &r[6];  indices[7] = &r[7];
        indices[8] = &r[8];  indices[9] = &r[9];  indices[10] = &r[10]; indices[11] = &r[11];

        r0 = (*indices[0]) & 63;
        r1 = ((*indices[0]) >> 6 | (*indices[1]) << 2) & 63;
        r2 = ((*indices[1]) >> 4 | (*indices[2]) << 4) & 63;
        r3 = ((*indices[2]) >> 2) & 63;
        r4 = (*indices[3]) & 63;
        r5 = ((*indices[3]) >> 6 | (*indices[4]) << 2) & 63;
        r6 = ((*indices[4]) >> 4 | (*indices[5]) << 4) & 63;
        r7 = ((*indices[5]) >> 2) & 63;
        r8 = (*indices[6]) & 63;
        r9 = ((*indices[6]) >> 6 | (*indices[7]) << 2) & 63;
        r10 = ((*indices[7]) >> 4 | (*indices[8]) << 4) & 63;
        r11 = ((*indices[8]) >> 2) & 63;
        r12 = (*indices[9]) & 63;
        r13 = ((*indices[9]) >> 6 | (*indices[10]) << 2) & 63;
        r14 = ((*indices[10]) >> 4 | (*indices[11]) << 4) & 63;
        r15 = ((*indices[11]) >> 2) & 63;

        reghisto[r0]++;
        reghisto[r1]++;
        reghisto[r2]++;
        reghisto[r3]++;
        reghisto[r4]++;
        reghisto[r5]++;
        reghisto[r6]++;
        reghisto[r7]++;
        reghisto[r8]++;
        reghisto[r9]++;
        reghisto[r10]++;
        reghisto[r11]++;
        reghisto[r12]++;
        reghisto[r13]++;
        reghisto[r14]++;
        reghisto[r15]++;

        r += 12;
    }
}
