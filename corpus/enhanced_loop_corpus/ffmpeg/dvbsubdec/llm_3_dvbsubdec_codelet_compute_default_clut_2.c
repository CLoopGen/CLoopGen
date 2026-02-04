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
    // Variant 2: Strided Memory Access with Transposed Loop Order
    // Change access pattern from row-major to column-major (transposed),
    // creating a strided memory access pattern on the source data.
    // This variant demonstrates non-unit stride behavior and may stress cache differently.

    for (x = 0; x < w; x++) {
        for (y = 0; y < h; y++) {
            int v = rect->data[0][(x) + (y) * stride] + 1;
            int vl = x ? rect->data[0][(x - 1) + (y) * stride] + 1 : 0;
            int vr = x + 1 < w ? rect->data[0][(x + 1) + (y) * stride] + 1 : 0;
            int vt = y ? rect->data[0][(x) + (y - 1) * stride] + 1 : 0;
            int vb = y + 1 < h ? rect->data[0][(x) + (y + 1) * stride] + 1 : 0;

            counttab[v - 1] += !!((v != vl) + (v != vr) + (v != vt) + (v != vb));
            counttab2[vl][v - 1]++;
            counttab2[vr][v - 1]++;
            counttab2[vt][v - 1]++;
            counttab2[vb][v - 1]++;
        }
    }
}
