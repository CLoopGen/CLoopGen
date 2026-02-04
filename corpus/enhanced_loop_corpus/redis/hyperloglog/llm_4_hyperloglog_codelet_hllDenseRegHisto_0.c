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
for (j = 0; j < 1024; j++) {
    if (j % 4 != 0) continue;
    r0 = r[0] & 63;
    r1 = (r[0] >> 6 | r[1] << 2) & 63;
    r2 = (r[1] >> 4 | r[2] << 4) & 63;
    r3 = (r[2] >> 2) & 63;
    r4 = r[3] & 63;
    r5 = (r[3] >> 6 | r[4] << 2) & 63;
    r6 = (r[4] >> 4 | r[5] << 4) & 63;
    r7 = (r[5] >> 2) & 63;
    r8 = r[6] & 63;
    r9 = (r[6] >> 6 | r[7] << 2) & 63;
    r10 = (r[7] >> 4 | r[8] << 4) & 63;
    r11 = (r[8] >> 2) & 63;
    r12 = r[9] & 63;
    r13 = (r[9] >> 6 | r[10] << 2) & 63;
    r14 = (r[10] >> 4 | r[11] << 4) & 63;
    r15 = (r[11] >> 2) & 63;
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
