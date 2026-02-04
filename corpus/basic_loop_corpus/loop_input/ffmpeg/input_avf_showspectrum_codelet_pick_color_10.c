#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

struct ColorTable {
    float a;
    float y;
    float u;
    float v;
};

#define COLOR_TABLE_ENTRIES 65536
#define CM_MAX 8

struct ColorTable color_table[CM_MAX][8];
float a;
int cm;
int i;

void init_vars() {
    for (int idx = 0; idx < CM_MAX; idx++) {
        for (int j = 0; j < 8; j++) {
            color_table[idx][j].a = (float)(rand() % 1000) / 100.0f;
            color_table[idx][j].y = (float)(rand() % 256);
            color_table[idx][j].u = (float)(rand() % 256);
            color_table[idx][j].v = (float)(rand() % 256);
        }
    }
    a = 50.0f;
    cm = rand() % CM_MAX;
    i = 0;
}