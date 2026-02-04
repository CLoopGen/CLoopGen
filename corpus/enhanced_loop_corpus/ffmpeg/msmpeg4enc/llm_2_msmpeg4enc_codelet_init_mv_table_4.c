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
    int n = tab->n;
    const uint8_t *mvx = tab->table_mvx;
    const uint8_t *mvy = tab->table_mvy;
    uint16_t *index = tab->table_mv_index;
    for (i = 0; i < n; i += 2) {
        int x1 = mvx[i];
        int y1 = mvy[i];
        index[(x1 << 6) | y1] = i;
        if (i + 1 < n) {
            int x2 = mvx[i + 1];
            int y2 = mvy[i + 1];
            index[(x2 << 6) | y2] = i + 1;
        }
    }
}
