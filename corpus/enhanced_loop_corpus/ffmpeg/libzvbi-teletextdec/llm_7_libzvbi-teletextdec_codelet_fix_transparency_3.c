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

extern AVSubtitleRect *sub_rect;
extern int resy;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *prev_pixel = NULL;
    for (iy = 0; iy < resy; iy++) {
        uint8_t *pixel = sub_rect->data[0] + iy * sub_rect->linesize[0];
        // Introduce a RAW (read-after-write) loop-carried dependency
        if (iy > 0 && prev_pixel != NULL) {
            pixel[0] = prev_pixel[0] + 1; // Current iteration reads result of prior write
        } else {
            pixel[0] = 0;
        }
        prev_pixel = pixel;
    }
}
