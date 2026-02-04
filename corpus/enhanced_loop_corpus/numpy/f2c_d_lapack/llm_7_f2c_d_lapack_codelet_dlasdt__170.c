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
        integer base_node = inode[ncrnt];
        integer base_left_dim = ndiml[ncrnt];
        integer base_right_dim = ndimr[ncrnt];
        integer left_half = base_left_dim / 2;
        integer right_half = base_right_dim / 2;
        ndiml[il] = left_half;
        ndimr[il] = base_left_dim - left_half - 1;
        inode[il] = base_node - ndimr[il] - 1;
        ndiml[ir] = right_half;
        ndimr[ir] = base_right_dim - right_half - 1;
        inode[ir] = base_node + right_half + 1;
    }
    llst <<= 1;
}
}
