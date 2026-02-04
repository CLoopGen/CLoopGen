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
        int idx = (x) + (y) * stride;
        int v = rect->data[0][idx] + 1;
        int neighbors = 0;
        int contributions = 0;

        if (x > 0) {
            int left = rect->data[0][idx - 1] + 1;
            neighbors += (v != left);
            counttab2[left][v - 1]++;
            contributions++;
        }
        if (x < w - 1) {
            int right = rect->data[0][idx + 1] + 1;
            neighbors += (v != right);
            counttab2[right][v - 1]++;
            contributions++;
        }
        if (y > 0) {
            int top = rect->data[0][idx - stride] + 1;
            neighbors += (v != top);
            counttab2[top][v - 1]++;
            contributions++;
        }
        if (y < h - 1) {
            int bottom = rect->data[0][idx + stride] + 1;
            neighbors += (v != bottom);
            counttab2[bottom][v - 1]++;
            contributions++;
        }

        counttab[v - 1] += (neighbors > 0);
    }
}
}
