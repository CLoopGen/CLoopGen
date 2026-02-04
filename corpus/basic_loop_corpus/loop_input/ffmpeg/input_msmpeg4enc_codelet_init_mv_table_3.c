#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct VLC {
    int bits;
    int16_t (*table)[2];
    int table_size;
    int table_allocated;
} VLC;

typedef struct MVTable {
    int n;
    const uint16_t *table_mv_code;
    const uint8_t *table_mv_bits;
    const uint8_t *table_mvx;
    const uint8_t *table_mvy;
    uint16_t *table_mv_index;
    VLC vlc;
} MVTable;

// Define external variables
int i;
MVTable *tab;

// Allocate memory for table_mv_index (4096 elements as per loop)
static uint16_t mv_index_data[4096];

void init_vars() {
    // Allocate and initialize tab
    tab = (MVTable *)calloc(1, sizeof(MVTable));
    if (!tab) return;

    // Initialize n to a reasonable value; used in loop assignment
    tab->n = 42; // arbitrary initial value

    // Initialize table_mv_index to point to allocated array
    tab->table_mv_index = mv_index_data;

    // Initialize other pointer fields to non-NULL to avoid undefined behavior
    // These are not accessed in the loop, but must be valid pointers
    static const uint16_t dummy_code[1] = {0};
    static const uint8_t dummy_bits[1] = {0};
    static const uint8_t dummy_vx[1] = {0};
    static const uint8_t dummy_vy[1] = {0};

    tab->table_mv_code = dummy_code;
    tab->table_mv_bits = dummy_bits;
    tab->table_mvx = dummy_vx;
    tab->table_mvy = dummy_vy;

    // Initialize VLC structure inside tab
    tab->vlc.bits = 0;
    tab->vlc.table = NULL;
    tab->vlc.table_size = 0;
    tab->vlc.table_allocated = 0;
}