#include <stdint.h>
#include <stdlib.h>
#include <string.h>

uint8_t *dst;
int linesize;
uint8_t *font;
int font_height;
int ch;
int fg;
int bg;
int char_y;
int mask;

#define FONT_CHARS 256
#define DATA_SIZE_MB 4
#define TOTAL_DATA_SIZE (DATA_SIZE_MB * 1024 * 1024)

static uint8_t internal_font_data[FONT_CHARS * 16]; // Max height 16 per char
static uint8_t internal_dst_data[TOTAL_DATA_SIZE];

void init_vars() {
    font_height = 16;
    ch = 65; // ASCII 'A'
    fg = 0xFF;
    bg = 0x00;
    linesize = 1024;
    
    font = internal_font_data;
    dst = internal_dst_data;
    
    memset(internal_font_data, 0, sizeof(internal_font_data));
    for (int i = 0; i < FONT_CHARS; i++) {
        for (int j = 0; j < font_height; j++) {
            internal_font_data[i * font_height + j] = rand() & 255;
        }
    }
    
    memset(internal_dst_data, 0, sizeof(internal_dst_data));
}