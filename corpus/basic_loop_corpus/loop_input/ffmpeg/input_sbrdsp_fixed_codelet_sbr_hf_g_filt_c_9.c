#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct SoftFloat {
    int32_t mant;
    int32_t exp;
} SoftFloat;

// Define the external variables
int (*Y)[2];
int (*X_high)[40][2];
SoftFloat *g_filt;
int m_max;
intptr_t ixh;
int m;
int64_t accu;

// Data size target: aim for around 10-50 million iterations to take ~0.01s
// We'll set m_max such that total data is about 100MB
#define DATA_SIZE (25 * 1024 * 1024)  // ~25M elements, adjust as needed

void init_vars() {
    // Set m_max to control loop iterations
    m_max = 2500000;  // 2.5M iterations should be in the right ballpark

    // Constrain ixh to valid range [0,39] for X_high[m][ixh]
    ixh = 20;

    // Allocate Y: m_max x 2 integers
    Y = malloc(m_max * sizeof(*Y));
    if (!Y) exit(1);

    // Allocate X_high: m_max x 40 x 2 integers
    X_high = malloc(m_max * sizeof(*X_high));
    if (!X_high) exit(1);

    // Allocate g_filt: m_max SoftFloats
    g_filt = malloc(m_max * sizeof(SoftFloat));
    if (!g_filt) exit(1);

    // Initialize all arrays with safe values
    for (int i = 0; i < m_max; i++) {
        // Initialize X_high[i][ixh][0] and [1] - other indices may exist but we only use ixh
        X_high[i][ixh][0] = (i % 32768) + 1;
        X_high[i][ixh][1] = ((i + 1000) % 32768) + 1;

        // Initialize g_filt with exp such that some pass the condition (22 - exp < 61)
        // This condition is always true if exp > -39, so we make exp in valid range
        g_filt[i].exp = (i % 50) - 10;  // exp from -10 to 39 -> condition always true
        g_filt[i].mant = (i % 16383) + 1;  // mant positive and reasonable

        // Initialize Y output locations
        Y[i][0] = 0;
        Y[i][1] = 0;
    }

    // Initialize accumulator
    accu = 0;
}