#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int stride;
extern int i;
extern int tblk[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Decreased depth: original is already flat, so we simulate "reduction" by unrolling the outer loop completely
dst[0] = ((5 * ((tblk[0]) + (tblk[1]) + (tblk[2])) + 2 * (tblk[3])) + 32) >> 6;
dst[1] = ((5 * ((tblk[0]) - (tblk[2]) - (tblk[3])) + 2 * (tblk[1])) + 32) >> 6;
dst[2] = ((5 * ((tblk[0]) - (tblk[2]) + (tblk[3])) - 2 * (tblk[1])) + 32) >> 6;
dst[3] = ((5 * ((tblk[0]) - (tblk[1]) + (tblk[2])) - 2 * (tblk[3])) + 32) >> 6;
dst += stride;

dst[0] = ((5 * ((tblk[4]) + (tblk[5]) + (tblk[6])) + 2 * (tblk[7])) + 32) >> 6;
dst[1] = ((5 * ((tblk[4]) - (tblk[6]) - (tblk[7])) + 2 * (tblk[5])) + 32) >> 6;
dst[2] = ((5 * ((tblk[4]) - (tblk[6]) + (tblk[7])) - 2 * (tblk[5])) + 32) >> 6;
dst[3] = ((5 * ((tblk[4]) - (tblk[5]) + (tblk[6])) - 2 * (tblk[7])) + 32) >> 6;
dst += stride;

dst[0] = ((5 * ((tblk[8]) + (tblk[9]) + (tblk[10])) + 2 * (tblk[11])) + 32) >> 6;
dst[1] = ((5 * ((tblk[8]) - (tblk[10]) - (tblk[11])) + 2 * (tblk[9])) + 32) >> 6;
dst[2] = ((5 * ((tblk[8]) - (tblk[10]) + (tblk[11])) - 2 * (tblk[9])) + 32) >> 6;
dst[3] = ((5 * ((tblk[8]) - (tblk[9]) + (tblk[10])) - 2 * (tblk[11])) + 32) >> 6;
dst += stride;

dst[0] = ((5 * ((tblk[12]) + (tblk[13]) + (tblk[14])) + 2 * (tblk[15])) + 32) >> 6;
dst[1] = ((5 * ((tblk[12]) - (tblk[14]) - (tblk[15])) + 2 * (tblk[13])) + 32) >> 6;
dst[2] = ((5 * ((tblk[12]) - (tblk[14]) + (tblk[15])) - 2 * (tblk[13])) + 32) >> 6;
dst[3] = ((5 * ((tblk[12]) - (tblk[13]) + (tblk[14])) - 2 * (tblk[15])) + 32) >> 6;
dst += stride;
}
