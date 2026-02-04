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
for (y = 0; y < h; y++) {
    int base_offset = y * stride;
    for (x = 0; x < w; x++) {
        int offset = x + base_offset;
        int v = rect->data[0][offset] + 1;
        int vl = (x > 0) ? rect->data[0][offset - 1] + 1 : 0;
        int vr = (x + 1 < w) ? rect->data[0][offset + 1] + 1 : 0;
        int vt = (y > 0) ? rect->data[0][offset - stride] + 1 : 0;
        int vb = (y + 1 < h) ? rect->data[0][offset + stride] + 1 : 0;

        int diff_count = !!((v != vl) + (v != vr) + (v != vt) + (v != vb));
        counttab[v - 1] += diff_count;

        // Introduce artificial WAW dependency by accumulating into a temporary
        // and updating counttab2 only after all increments are computed.
        int temp_vl = (vl > 0) ? vl : 1;
        int temp_vr = (vr > 0) ? vr : 1;
        int temp_vt = (vt > 0) ? vt : 1;
        int temp_vb = (vb > 0) ? vb : 1;

        counttab2[temp_vl][v - 1]++;
        counttab2[temp_vr][v - 1]++;
        counttab2[temp_vt][v - 1]++;
        counttab2[temp_vb][v - 1]++;
    }
}
}
