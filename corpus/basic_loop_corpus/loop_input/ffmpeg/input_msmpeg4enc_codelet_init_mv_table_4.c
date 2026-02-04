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

static uint8_t *generated_table_mvx;
static uint8_t *generated_table_mvy;
static uint16_t *generated_table_mv_index;
static const uint16_t *dummy_table_mv_code;
static const uint8_t *dummy_table_mv_bits;

MVTable *tab;
int i;
int x;
int y;

void init_vars() {
    size_t data_size = 1 << 20; // ~1MB of index space, reasonable for ~0.01s runtime

    generated_table_mvx = malloc(data_size * sizeof(uint8_t));
    generated_table_mvy = malloc(data_size * sizeof(uint8_t));
    generated_table_mv_index = malloc(data_size * 64 * sizeof(uint16_t)); // (x<<6)|y => up to 64*64 per block?

    dummy_table_mv_code = calloc(data_size, sizeof(uint16_t));
    dummy_table_mv_bits = calloc(data_size, sizeof(uint8_t));

    for (size_t idx = 0; idx < data_size; idx++) {
        generated_table_mvx[idx] = (uint8_t)((idx * 7) & 0x3F); // bound x to 6 bits
        generated_table_mvy[idx] = (uint8_t)((idx * 11) & 0x3F); // bound y to 6 bits
    }

    tab = malloc(sizeof(MVTable));
    tab->n = (int)data_size;
    tab->table_mv_code = dummy_table_mv_code;
    tab->table_mv_bits = dummy_table_mv_bits;
    tab->table_mvx = generated_table_mvx;
    tab->table_mvy = generated_table_mvy;
    tab->table_mv_index = generated_table_mv_index;
    tab->vlc.bits = 0;
    tab->vlc.table = NULL;
    tab->vlc.table_size = 0;
    tab->vlc.table_allocated = 0;
}