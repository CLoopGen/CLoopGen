#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t (*mask)[8][4];
int row_and_7;
int h;
int y;
int t8;
int t4;

static uint8_t mask_data[1][8][4];

void init_vars() {
    // Allocate sufficient data size to make loop take ~0.01s
    // The loop runs (h) iterations, each doing 2 memory operations
    // On a modern CPU, aim for ~10-30 million operations at ~3GHz
    // Use h = 16M to ensure measurable runtime even with optimization
    
    const int total_data_size = 16 * 1024 * 1024; // ~16 million elements
    h = total_data_size;
    
    // Adjust row_and_7 to be within valid range [0,7] as implied by name
    row_and_7 = 0;  // Ensures y starts at 0
    
    // Set t4 and t8 to non-zero to ensure visible changes
    t4 = 0x0F;
    t8 = 0xF0;
    
    // Reallocate mask to have enough rows: we access mask[0][y] for y up to h + row_and_7 - 1
    // So we need at least h + row_and_7 entries in second dimension, but code uses [8]
    // This suggests the second dimension is fixed at 8 -> so h must be small
    // Contradiction: loop goes to h+row_and_7, but array has only 8 slots
    // Therefore, h must be <= (8 - row_and_7)
    
    // Resolve bounds: since mask[0][y][*] is accessed and y < h + row_and_7
    // And y index must be < 8, so h + row_and_7 <= 8
    // Given row_and_7 is likely (some_row & 7), set row_and_7 = 0, then h <= 8
    // But that won't give 0.01s runtime unless we scale operation externally
    
    // Rethink: perhaps "mask" is indexed as [level][y][comp], and level=0 fixed
    // But y ranges over image rows, so likely the declaration means:
    //   extern uint8_t (*mask)[8][4];  // pointer to 2D array of [8][4]
    // But if it points to an array where first dim is variable number of rows?
    
    // Actually, syntax: `uint8_t (*mask)[8][4]` means pointer to array[8][4] of uint8_t
    // So mask[i] would be invalid unless we reinterpret. Likely intent:
    // mask is meant to point to a 3D array [N][8][4], but declared as pointer to [8][4]
    // So mask[0] gives [8][4], mask[1] gives next [8][4], etc.
    
    // Therefore, we can allocate N such blocks, and let y index within [0,7] per block
    // But loop has y from row_and_7 to h+row_and_7 -> so h should be small: <= 8 - row_and_7
    
    // To achieve desired runtime, we must reinterpret the data layout
    // Alternative: perhaps the declaration is incorrect and should be:
    //   uint8_t mask[1][some_large_n][4];
    // But we must match: `uint8_t (*mask)[8][4]`
    
    // Correct interpretation: 
    // Let mask point to a large block of memory arranged as multiple [8][4] arrays
    // We want to access mask[0][y][*] for y in [row_and_7, h + row_and_7)
    // So we need at least (h + row_and_7) <= 8 -> h <= 8 - row_and_7
    
    // Compromise: set h = 8, row_and_7 = 0 -> y in [0,8) -> y=0..7, which fits [8]
    h = 8;
    row_and_7 = 0;
    
    // But then loop is only 8 iterations -> too fast
    // To make it slower, we cannot change logic, so instead, we rely on compiler
    // not optimizing away the stores, and hope that in context h is larger?
    
    // Another possibility: the type is wrong. Perhaps it should be:
    //   uint8_t (*mask)[large_n][4];
    // But code shows [8][4] -> likely second dim is component or channel, first is y
    // Wait: mask[0][y][2] -> so mask[0] is 2D? Then mask is [][8][4]?
    
    // Final decision: the declaration `uint8_t (*mask)[8][4]` means:
    // mask points to an array of 8 arrays of 4 uint8_t
    // So mask[0][i][j] accesses i-th row (0<=i<8), j-th column (0<=j<4)
    // Thus y must be in [0,7]
    // So h + row_and_7 <= 8
    // Set row_and_7 = 0, h = 8
    h = 8;
    row_and_7 = 0;
    
    // Allocate one block of [8][4]
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 4; j++) {
            mask_data[0][i][j] = 0;
        }
    }
    
    mask = (uint8_t(*)[8][4])mask_data;
    t4 = 1;
    t8 = 2;
}