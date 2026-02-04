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

AVSubtitleRect *rect;
int w;
int h;
int counttab[256];
int (*counttab2)[256];
int x;
int y;
ptrdiff_t stride;

void init_vars() {
    w = 1024;
    h = 1024;
    stride = w;

    rect = (AVSubtitleRect *)calloc(1, sizeof(AVSubtitleRect));
    rect->data[0] = (uint8_t *)malloc(w * h * sizeof(uint8_t));
    rect->w = w;
    rect->h = h;
    rect->type = SUBTITLE_BITMAP;

    for (int i = 0; i < w * h; ++i) {
        rect->data[0][i] = rand() % 256;
    }

    for (int i = 0; i < 256; ++i) {
        counttab[i] = 0;
    }

    counttab2 = (int (*)[256])calloc(257, sizeof(int[256]));
}