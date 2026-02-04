#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct _StringInfo {
    char *path;
    unsigned char *datum;
    size_t length;
    size_t signature;
    char *name;
} StringInfo;

StringInfo *string_info;
unsigned char *p;
ssize_t i;
unsigned char *q;
unsigned char hex_digits[16] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};

static unsigned char *buffer_p;
static unsigned char *buffer_q;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64 MB for ~0.01 sec runtime

    buffer_p = (unsigned char *)calloc(data_size, sizeof(unsigned char));
    buffer_q = (unsigned char *)calloc(data_size * 2, sizeof(unsigned char));

    if (!buffer_p || !buffer_q) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; idx++) {
        buffer_p[idx] = (unsigned char)(idx & 0xFF);
    }

    string_info = (StringInfo *)malloc(sizeof(StringInfo));
    if (!string_info) {
        exit(1);
    }

    string_info->datum = buffer_p;
    string_info->length = data_size;
    string_info->path = NULL;
    string_info->signature = 0;
    string_info->name = NULL;

    p = buffer_p;
    q = buffer_q;
    i = 0;
}