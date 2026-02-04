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
        // Use consecutive memory layout by precomputing base indices
        integer idx_l = il;
        integer idx_r = ir;
        integer idx_ncrnt = ncrnt;

        ndiml[idx_l] = ndiml[idx_ncrnt] / 2;
        ndimr[idx_l] = ndiml[idx_ncrnt] - ndiml[idx_l] - 1;
        inode[idx_l] = inode[idx_ncrnt] - ndimr[idx_l] - 1;

        ndiml[idx_r] = ndimr[idx_ncrnt] / 2;
        ndimr[idx_r] = ndimr[idx_ncrnt] - ndiml[idx_r] - 1;
        inode[idx_r] = inode[idx_ncrnt] + ndiml[idx_r] + 1;
    }
    llst <<= 1;
}
}
