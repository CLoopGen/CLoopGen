#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int m1[8][8];
extern int m2[8][8];
extern int m3[8][8];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    // Change memory access pattern to consecutive by precomputing column-major strides
    // Simulate a transposed access pattern using linear indexing for better locality
    int col = i;
    int row;
    for (row = 0; row < 8; row++) {
        m3[row][col] = (row < 4) ? (m2[row][col] + m2[row+4][col]) : (m2[row-4][col] - m2[row][col]);
    }
    for (row = 0; row < 8; row++) {
        if (row < 4)
            m1[row][col] = (row % 2 == 0) ? (m3[row/2*2][col] + m3[row/2*2+2][col]) : (m3[row/2*2-1][col] + m3[row/2*2+1][col]);
        else
            m1[row][col] = (row % 2 == 0) ? (m3[row-4][col] + m3[row-2][col]) : (m3[row-5][col] + m3[row-3][col]);
    }
    for (row = 0; row < 8; row++) {
        if (row % 2 == 0)
            m2[row][col] = m1[row][col] + m1[row+1][col];
        else
            m2[row][col] = m1[row-1][col] - m1[row][col];
    }
}
}
