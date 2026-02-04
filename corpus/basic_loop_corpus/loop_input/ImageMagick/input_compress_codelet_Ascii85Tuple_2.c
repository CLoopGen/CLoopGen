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

Ascii85Info *ascii85_info;
size_t code;
size_t i;
size_t quantum;
size_t x;

void init_vars() {
    ascii85_info = (Ascii85Info*)malloc(sizeof(Ascii85Info));
    if (!ascii85_info) {
        exit(1);
    }
    ascii85_info->offset = 0;
    ascii85_info->line_break = 80;
    for (int j = 0; j < 6; j++) {
        ascii85_info->tuple[j] = '\0';
    }
    for (int j = 0; j < 10; j++) {
        ascii85_info->buffer[j] = 0;
    }
    code = 0x12345678UL;
    i = 0;
    quantum = 85 * 85 * 85 * 85;
    x = 0;
}