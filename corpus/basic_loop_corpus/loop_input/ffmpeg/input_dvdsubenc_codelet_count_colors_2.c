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

AVSubtitleRect *r;
unsigned int count[256];
int x;
int y;
uint8_t *p;

static uint8_t *buffer = NULL;
static AVSubtitleRect r_storage;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of input data

    buffer = (uint8_t*)calloc(data_size, sizeof(uint8_t));
    if (!buffer) exit(1);

    for (size_t i = 0; i < data_size; i++) {
        buffer[i] = rand() % 256;
    }

    r_storage.w = 1024;
    r_storage.h = 1024;
    r_storage.linesize[0] = 1024;
    r_storage.data[0] = buffer;

    r = &r_storage;
    p = r->data[0];

    for (int i = 0; i < 256; i++) {
        count[i] = 0;
    }
}