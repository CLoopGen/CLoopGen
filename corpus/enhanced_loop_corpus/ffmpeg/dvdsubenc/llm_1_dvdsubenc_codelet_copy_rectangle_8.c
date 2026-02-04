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
    int index = 0;
    int total_pixels = src->h * src->w;
    for (index = 0; index < total_pixels; index++) {
        *(q++) = cmap[*(p++)];
        if ((index + 1) % src->w == 0) {
            p += src->linesize[0] - src->w;
            q += dst->linesize[0] - src->w;
        }
    }
}
