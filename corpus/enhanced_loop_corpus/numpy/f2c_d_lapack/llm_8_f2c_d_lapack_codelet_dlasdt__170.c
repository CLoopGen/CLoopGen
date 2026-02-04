#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern integer *inode;
extern integer *ndiml;
extern integer *ndimr;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer il;
extern integer ir;
extern integer nlvl;
extern integer llst;
extern integer ncrnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (nlvl = 1; nlvl <= i__1; ++nlvl) {
    i__2 = llst - 1;
    for (i__ = 0; i__ <= i__2; ++i__) {
        il += 2;
        ir += 2;
        ncrnt = llst + i__;
        integer temp_l = ndiml[ncrnt];
        integer half_temp_l = temp_l / 2;
        ndiml[il] = half_temp_l;
        ndimr[il] = temp_l - half_temp_l - 1;
        inode[il] = inode[ncrnt] - ndimr[il] - 1;

        integer temp_r = ndimr[ncrnt];
        integer half_temp_r = temp_r / 2;
        ndiml[ir] = half_temp_r;
        ndimr[ir] = temp_r - half_temp_r - 1;
        inode[ir] = inode[ncrnt] + ndiml[ir] + 1;
    }
    llst <<= 1;
}
}
