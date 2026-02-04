#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>

typedef int int32type;

typedef struct {
    int32type magic_number;
    char time_stamp[64];
    int32type dims[4];
    int32type header_bytes;
    int32type order;
} gauge_header;

gauge_header *gh;
int i;
int dims[4];

void init_vars() {
    gh = (gauge_header*)malloc(sizeof(gauge_header));
    if (!gh) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    gh->magic_number = 0x12345678;
    memset(gh->time_stamp, 0, 64);
    strcpy(gh->time_stamp, "2023-11-15T12:00:00Z");
    gh->header_bytes = sizeof(gauge_header);
    gh->order = 1;

    for (int j = 0; j < 4; j++) {
        dims[j] = (j + 1) * 100;
    }

    i = 0;
}