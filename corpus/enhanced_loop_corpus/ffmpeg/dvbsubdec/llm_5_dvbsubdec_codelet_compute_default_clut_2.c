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
        int addr = (x) + (y) * stride;
        int v = rect->data[0][addr] + 1;
        int neighbors[4] = {0};
        int valid[4] = {0};

        if (x > 0) {
            neighbors[0] = rect->data[0][(x - 1) + (y) * stride] + 1;
            valid[0] = 1;
        }
        if (x < w - 1) {
            neighbors[1] = rect->data[0][(x + 1) + (y) * stride] + 1;
            valid[1] = 1;
        }
        if (y > 0) {
            neighbors[2] = rect->data[0][(x) + (y - 1) * stride] + 1;
            valid[2] = 1;
        }
        if (y < h - 1) {
            neighbors[3] = rect->data[0][(x) + (y + 1) * stride] + 1;
            valid[3] = 1;
        }

        int edge_count = 0;
        for (int i = 0; i < 4; i++) {
            if (valid[i] && v != neighbors[i])
                edge_count++;
            if (valid[i])
                counttab2[neighbors[i]][v - 1]++;
        }

        counttab[v - 1] += edge_count > 0;
    }
}
}
