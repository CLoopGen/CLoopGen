#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;

integer *inode;
integer *ndiml;
integer *ndimr;
integer i__1;
integer i__2;
integer i__;
integer il;
integer ir;
integer nlvl;
integer llst;
integer ncrnt;

void init_vars() {
    // Set parameters to control loop execution time (~0.01 seconds)
    // Based on typical modern CPU performance, aim for moderate data size
    
    i__1 = 10;          // outer loop iterations
    llst = 1;           // initial value for list start
    
    // Calculate total number of elements accessed in worst case
    // Inner loop runs 'llst' times per level, and llst doubles each iteration
    // Max llst after 10 levels: 2^10 = 1024
    // Max index used: ir += 2 each time -> max ir ~ 2 * (sum of llst over levels)
    // We'll allocate generously to prevent out-of-bounds
    
    size_t total_size = 1 << 16;  // 65536 elements per array
    
    // Allocate arrays with sufficient space
    ndiml = (integer*)calloc(total_size, sizeof(integer));
    ndimr = (integer*)calloc(total_size, sizeof(integer));
    inode = (integer*)calloc(total_size, sizeof(integer));
    
    // Initialize base values to avoid undefined behavior
    for (size_t idx = 0; idx < total_size; ++idx) {
        ndiml[idx] = 100 + idx;   // arbitrary non-zero values
        ndimr[idx] = 150 + idx;
        inode[idx] = 200 + idx;
    }
    
    // Initialize scalar variables used in loop
    il = 0;
    ir = 1;
    nlvl = 0;
    i__ = 0;
    ncrnt = 0;
}