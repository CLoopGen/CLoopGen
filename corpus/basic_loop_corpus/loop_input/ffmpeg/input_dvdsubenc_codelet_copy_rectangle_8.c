#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct AVPicture {
    uint8_t *data[8];
    int linesize[8];
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
    AVPicture pict;
    uint8_t *data[4];
    int linesize[4];
    enum AVSubtitleType type;
    char *text;
    char *ass;
    int flags;
} AVSubtitleRect;

AVSubtitleRect *dst;
AVSubtitleRect *src;
int cmap[256];
int x;
int y;
uint8_t *p;
uint8_t *q;

static uint8_t *src_data_ptr;
static uint8_t *dst_data_ptr;

void init_vars() {
    src = (AVSubtitleRect *)calloc(1, sizeof(AVSubtitleRect));
    dst = (AVSubtitleRect *)calloc(1, sizeof(AVSubtitleRect));

    src->w = 4096;
    src->h = 64;
    src->linesize[0] = src->w;
    dst->linesize[0] = src->w;

    src->nb_colors = 256;
    src->type = SUBTITLE_BITMAP;
    dst->type = SUBTITLE_BITMAP;

    for (int i = 0; i < 256; i++) {
        cmap[i] = (i * 199) % 256;
    }

    src_data_ptr = (uint8_t *)malloc(src->h * src->linesize[0]);
    dst_data_ptr = (uint8_t *)malloc(src->h * dst->linesize[0]);

    src->data[0] = src_data_ptr;
    dst->data[0] = dst_data_ptr;

    p = src->data[0];
    q = dst->data[0];

    x = 0;
    y = 0;
}