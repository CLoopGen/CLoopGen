#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int ns = 1;
int os = 1;
uint16_t *nptr = NULL;
uint16_t *optr = NULL;
int w = 0;
int64_t bdif = 0;
int64_t tdif = 0;
int t = 0;
uint16_t *rend = NULL;

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS ((DATA_SIZE_MB * 1024 * 1024) / sizeof(uint16_t))

static uint16_t *nptr_data = NULL;
static uint16_t *optr_data = NULL;

void init_vars() {
    const size_t total_needed = TOTAL_ELEMENTS + 4; // Add padding for safe indexing with offsets
    
    nptr_data = (uint16_t*)aligned_alloc(32, total_needed * sizeof(uint16_t));
    optr_data = (uint16_t*)aligned_alloc(32, total_needed * sizeof(uint16_t));
    
    if (!nptr_data || !optr_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    
    // Initialize data with pseudo-random but deterministic values
    srand(12345);
    for (size_t i = 0; i < total_needed; i++) {
        nptr_data[i] = rand() & 0xFFFF;
        optr_data[i] = rand() & 0xFFFF;
    }
    
    // Set initial pointers and loop parameters
    nptr = nptr_data + 2;        // Offset by 2 to allow [-(ns)] and [(ns)<<1] access
    optr = optr_data + 2;
    w = TOTAL_ELEMENTS - 4;      // Ensure we don't exceed bounds in the loop
    rend = NULL;                 // Will be set in loop
    bdif = 0;
    tdif = 0;
    t = 0;
}