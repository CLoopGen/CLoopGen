#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
struct _Ascii85Info {
    ssize_t offset;
    ssize_t line_break;
    char tuple[6];
    unsigned char buffer[10];
};


typedef struct _Ascii85Info Ascii85Info;

extern Ascii85Info *ascii85_info;
extern size_t code;
extern size_t i;
extern size_t quantum;
extern size_t x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; i += 1) {
        x = (code / quantum);
        code -= quantum * x;
        ascii85_info->tuple[i] = (char)(x + (int)'!');
        quantum /= 85L;
        if (i == 2 && code < 100) {
            ascii85_info->tuple[3] = '!';
            break;
        }
    }
}
