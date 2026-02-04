#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t (*mask)[8][4];
int row_and_7;
int h;
int y;
int m_col;
int step1d;

void init_vars() {
    const size_t total_size = 16 * 1024 * 1024; // 16 MB to ensure ~0.01 sec runtime
    const size_t num_elements = total_size / (8 * 4 * sizeof(uint8_t));
    
    // Allocate mask as a large array of [N][8][4] uint8_t
    uint8_t (*m)[8][4] = calloc(num_elements, sizeof(*m));
    if (!m) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    mask = m;

    // Set bounds so that loop accesses are valid: y in [row_and_7, h + row_and_7 - 1) with step step1d
    row_and_7 = 0;
    h = (num_elements > 8) ? 8 : num_elements; // Ensure h is within allocated dimensions
    step1d = 1;
    m_col = 1; // Arbitrary non-zero value for OR operation

    // Ensure y index stays within [0,7] for second dimension of mask[1][y][0]
    if (h + row_and_7 - 1 >= 8) {
        h = 8 - row_and_7 + 1;
    }
}