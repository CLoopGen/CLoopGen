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

AVSubtitleRect *sub_rect;
int resy;
int iy;

static uint8_t *pixel_data = NULL;
static AVSubtitleRect sub_rect_storage;

void init_vars() {
    resy = 2048;
    sub_rect = &sub_rect_storage;
    sub_rect->w = 1920;
    sub_rect->h = resy;
    sub_rect->linesize[0] = 1920;
    sub_rect->nb_colors = 256;
    sub_rect->type = SUBTITLE_BITMAP;
    sub_rect->flags = 0;
    sub_rect->x = 0;
    sub_rect->y = 0;
    sub_rect->text = NULL;
    sub_rect->ass = NULL;

    size_t data_size = (size_t)sub_rect->linesize[0] * resy;
    pixel_data = (uint8_t *)calloc(data_size, 1);
    if (!pixel_data) {
        exit(1);
    }
    sub_rect->data[0] = pixel_data;
    for (int i = 1; i < 4; i++) {
        sub_rect->data[i] = NULL;
        sub_rect->linesize[i] = 0;
    }
}