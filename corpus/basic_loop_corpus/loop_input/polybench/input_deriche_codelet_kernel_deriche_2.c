#include <stdio.h>
#include <inttypes.h>

int w = 1920;
int h = 1080;

float imgIn[4096][2160];
float y2[4096][2160];

int i;
int j;
float xp1;
float xp2;
float yp1;
float yp2;
float a3 = 0.25f;
float a4 = 0.5f;
float b1 = 0.75f;
float b2 = 1.0f;

void init_vars() {
    for (int i = 0; i < 4096; ++i) {
        for (int j = 0; j < 2160; ++j) {
            imgIn[i][j] = (float)(i * j % 100) / 100.0f;
            y2[i][j] = 0.0f;
        }
    }
}