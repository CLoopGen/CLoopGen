#include <stdio.h>

#include <inttypes.h>

extern int *diff;
extern int j;
extern int m1[8][8];
extern int m2[8][8];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < 8; ++j) {
    int base_idx = j * 8;
    // Introduce artificial WAW and WAR dependencies by reordering and splitting operations
    // First, write intermediate sums to m2 with delayed overwrites (WAW on m2[j][*])
    m2[j][0] = diff[base_idx] + diff[base_idx + 4];
    m2[j][1] = diff[base_idx + 1] + diff[base_idx + 5];
    m2[j][2] = diff[base_idx + 2] + diff[base_idx + 6];
    m2[j][3] = diff[base_idx + 3] + diff[base_idx + 7];
    m2[j][4] = diff[base_idx] - diff[base_idx + 4];
    m2[j][5] = diff[base_idx + 1] - diff[base_idx + 5];
    m2[j][6] = diff[base_idx + 2] - diff[base_idx + 6];
    m2[j][7] = diff[base_idx + 3] - diff[base_idx + 7];

    // Use m2 to compute m1 — introduces RAW dependency on m2 from previous statements
    m1[j][0] = m2[j][0] + m2[j][2];
    m1[j][1] = m2[j][1] + m2[j][3];
    m1[j][2] = m2[j][0] - m2[j][2];
    m1[j][3] = m2[j][1] - m2[j][3];
    m1[j][4] = m2[j][4] + m2[j][6];
    m1[j][5] = m2[j][5] + m2[j][7];
    m1[j][6] = m2[j][4] - m2[j][6];
    m1[j][7] = m2[j][5] - m2[j][7];

    // Reuse m1 values immediately in m2 — creates WAR hazard if loop were parallelized
    // Also creates loop-carried anti-dependence if j+1 writes m2 before j reads it (not here, but structurally)
    m2[j][0] = m1[j][0] + m1[j][1];
    m2[j][1] = m1[j][0] - m1[j][1];
    m2[j][2] = m1[j][2] + m1[j][3];
    m2[j][3] = m1[j][2] - m1[j][3];
    m2[j][4] = m1[j][4] + m1[j][5];
    m2[j][5] = m1[j][4] - m1[j][5];
    m2[j][6] = m1[j][6] + m1[j][7];
    m2[j][7] = m1[j][6] - m1[j][7];
}
}
