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
    uint8_t *base = sub_rect->data[0];
    int line_stride = sub_rect->linesize[0];
    for (iy = 0; iy < resy; iy++) {
        uint8_t *pixel = base + iy * line_stride;
        // Introduce a WAW dependency by writing to a common variable in each iteration
        pixel[0] = iy; // Write access creates WAW if multiple iterations write to same offset
    }
}
