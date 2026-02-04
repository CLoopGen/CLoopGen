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
    for (x = 0; x < w; x++) {
        int v = rect->data[0][(x) + (y) * stride] + 1;
        int vl = 0, vr = 0, vt = 0, vb = 0;

        if (x > 0)
            vl = rect->data[0][(x - 1) + (y) * stride] + 1;
        if (x < w - 1)
            vr = rect->data[0][(x + 1) + (y) * stride] + 1;
        if (y > 0)
            vt = rect->data[0][(x) + (y - 1) * stride] + 1;
        if (y < h - 1)
            vb = rect->data[0][(x) + (y + 1) * stride] + 1;

        int diff_count = 0;
        if (v != vl) diff_count++;
        if (v != vr) diff_count++;
        if (v != vt) diff_count++;
        if (v != vb) diff_count++;

        counttab[v - 1] += diff_count > 0;

        counttab2[vl][v - 1]++;
        counttab2[vr][v - 1]++;
        counttab2[vt][v - 1]++;
        counttab2[vb][v - 1]++;
    }
}
}
