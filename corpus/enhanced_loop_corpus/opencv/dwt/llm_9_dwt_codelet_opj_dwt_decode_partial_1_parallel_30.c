#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

typedef uint32_t OPJ_UINT32;

extern OPJ_INT32 *a;
extern OPJ_INT32 dn;
extern OPJ_INT32 win_l_x1;
extern OPJ_INT32 i;
extern OPJ_UINT32 off;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (i < win_l_x1) {
    OPJ_INT32 j = i;
    OPJ_INT32 limit = win_l_x1 > dn ? dn : win_l_x1;
    for (; j < limit; j += 2) {
        for (off = 0; off < 4; off++) {
            OPJ_UINT32 idx1 = (OPJ_UINT32)(j) * 8 + off;
            OPJ_UINT32 idx2 = (j + 1) < win_l_x1 ? ((OPJ_UINT32)(j + 1) * 8 + off) : idx1;

            OPJ_UINT32 src_prev_j = (j - 1) < 0 ? (1 + 0U * 2) * 4 + off : 
                                    (j - 1) >= dn ? (1 + (OPJ_UINT32)(dn - 1) * 2) * 4 + off : 
                                    (1 + (OPJ_UINT32)(j - 1) * 2) * 4 + off;
            OPJ_UINT32 src_curr_j = j < 0 ? (1 + 0U * 2) * 4 + off : 
                                    j >= dn ? (1 + (OPJ_UINT32)(dn - 1) * 2) * 4 + off : 
                                    (1 + (OPJ_UINT32)(j) * 2) * 4 + off;

            OPJ_INT32 sum_j = a[src_prev_j] + a[src_curr_j] + 2;
            a[idx1] -= (sum_j >> 2);

            if (j + 1 < win_l_x1 && j + 1 < dn) {
                OPJ_UINT32 src_prev_j1 = j >= dn ? (1 + (OPJ_UINT32)(dn - 1) * 2) * 4 + off : 
                                         (j) < 0 ? (1 + 0U * 2) * 4 + off : 
                                         (1 + (OPJ_UINT32)(j) * 2) * 4 + off;
                OPJ_UINT32 src_curr_j1 = (j + 1) >= dn ? (1 + (OPJ_UINT32)(dn - 1) * 2) * 4 + off : 
                                         (1 + (OPJ_UINT32)(j + 1) * 2) * 4 + off;
                OPJ_INT32 sum_j1 = a[src_prev_j1] + a[src_curr_j1] + 2;
                a[idx2] -= (sum_j1 >> 2);
            }
        }
    }
    i = limit;
}
}
