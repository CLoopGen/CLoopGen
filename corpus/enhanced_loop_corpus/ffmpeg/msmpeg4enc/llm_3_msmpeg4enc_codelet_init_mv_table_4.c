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

extern MVTable *tab;
extern int i;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    uint16_t *idx_ptr = tab->table_mv_index;
    const uint8_t *mvx = tab->table_mvx;
    const uint8_t *mvy = tab->table_mvy;
    for (i = tab->n - 1; i >= 0; i--) {
        x = mvx[i];
        y = mvy[i];
        idx_ptr[(x << 6) | y] = i;
    }
}
