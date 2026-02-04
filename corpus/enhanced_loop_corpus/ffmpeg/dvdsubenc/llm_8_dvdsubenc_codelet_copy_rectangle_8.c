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

extern AVSubtitleRect *dst;
extern AVSubtitleRect *src;
extern int cmap[];
extern int x;
extern int y;
extern uint8_t *p;
extern uint8_t *q;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int y, x;
    for (y = 0; y < src->h; y++) {
        for (x = 0; x < src->w; x += 2) {
            if (x + 1 < src->w) {
                uint8_t val1 = *(p++);
                uint8_t val2 = *(p++);
                *(q++) = cmap[val1];
                *(q++) = cmap[val2];
            } else {
                uint8_t val = *(p++);
                *(q++) = cmap[val];
            }
        }
        p += src->linesize[0] - src->w;
        q += dst->linesize[0] - src->w;
    }
}
