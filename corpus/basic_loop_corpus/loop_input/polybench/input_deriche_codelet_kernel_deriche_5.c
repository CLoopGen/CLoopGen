#include <stdio.h>
#include <inttypes.h>

int w = 1920;
int h = 1080;

float imgOut[4096][2160];
float y2[4096][2160];

int i;
int j;

float tp1;
float tp2;
float yp1;
float yp2;

float a7 = 0.25f;
float a8 = 0.5f;
float b1 = 0.75f;
float b2 = 1.0f;

void init_vars() {
    for (int j = 0; j < h; j++) {
        for (int i = 0; i < w; i++) {
            imgOut[i][j] = (float)(i * j % 100) / 100.0f;
            y2[i][j] = 0.0f;
        }
    }
    tp1 = 0.0f;
    tp2 = 0.0f;
    yp1 = 0.0f;
    yp2 = 0.0f;
}