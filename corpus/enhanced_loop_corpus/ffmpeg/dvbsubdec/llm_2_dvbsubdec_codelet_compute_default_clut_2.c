#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AVPicture {
    uint8_t *data[8] __attribute__((deprecated("")));
    int linesize[8] __attribute__((deprecated("")));
} AVPicture;

enum AVSubtitleType {
    SUBTITLE_NONE,
    SUBTITLE_BITMAP,
    SUBTITLE_TEXT,
    SUBTITLE_ASS
};


typedef struct AVSubtitleRect {
    int x;
    int y;
    int w;
    int h;
    int nb_colors;
    AVPicture pict __attribute__((deprecated("")));
    uint8_t *data[4];
    int linesize[4];
    enum AVSubtitleType type;
    char *text;
    char *ass;
    int flags;
} AVSubtitleRect;

extern AVSubtitleRect *rect;
extern int w;
extern int h;
extern int counttab[256];
extern int (*counttab2)[256];
extern int x;
extern int y;
extern ptrdiff_t stride;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access with Prefetched Indices
    // Instead of computing pixel offsets repeatedly, precompute base pointers per row
    // and access data sequentially. This improves cache locality.

    for (y = 0; y < h; y++) {
        uint8_t *row = rect->data[0] + y * stride;
        uint8_t *row_above = y ? rect->data[0] + (y - 1) * stride : NULL;
        uint8_t *row_below = y + 1 < h ? rect->data[0] + (y + 1) * stride : NULL;

        for (x = 0; x < w; x++) {
            int v = row[x] + 1;
            int vl = x ? row[x - 1] + 1 : 0;
            int vr = x + 1 < w ? row[x + 1] + 1 : 0;
            int vt = row_above ? row_above[x] + 1 : 0;
            int vb = row_below ? row_below[x] + 1 : 0;

            counttab[v - 1] += !!((v != vl) + (v != vr) + (v != vt) + (v != vb));
            counttab2[vl][v - 1]++;
            counttab2[vr][v - 1]++;
            counttab2[vt][v - 1]++;
            counttab2[vb][v - 1]++;
        }
    }
}
