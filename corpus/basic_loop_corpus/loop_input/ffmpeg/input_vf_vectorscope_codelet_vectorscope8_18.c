#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int slinesizex;
int slinesizey;
int slinesized;
int dlinesize;
int h;
int w;
uint8_t *spx;
uint8_t *spy;
uint8_t *spd;
uint8_t *dpx;
uint8_t *dpy;
uint8_t *dpd;
int tmin;
int tmax;
int i;
int j;

static uint8_t spx_data[1024 * 1024];
static uint8_t spy_data[1024 * 1024];
static uint8_t spd_data[1024 * 1024];
static uint8_t dpd_data[1024 * 1024];
static uint8_t dpx_data[1024 * 1024];
static uint8_t dpy_data[1024 * 1024];

void init_vars() {
    h = 1024;
    w = 1024;
    slinesizex = w;
    slinesizey = w;
    slinesized = w;
    dlinesize = w;

    tmin = 20;
    tmax = 200;

    spx = spx_data;
    spy = spy_data;
    spd = spd_data;
    dpx = dpx_data;
    dpy = dpy_data;
    dpd = dpd_data;

    memset(spx_data, 0, sizeof(spx_data));
    memset(spy_data, 0, sizeof(spy_data));
    memset(spd_data, 0, sizeof(spd_data));
    memset(dpx_data, 0, sizeof(dpx_data));
    memset(dpy_data, 0, sizeof(dpy_data));
    memset(dpd_data, 0, sizeof(dpd_data));

    for (int idx = 0; idx < h * w; idx++) {
        spx_data[idx] = rand() % 256;
        spy_data[idx] = rand() % 256;
        spd_data[idx] = rand() % 256;
    }

    for (int idx = 0; idx < w * w; idx++) {
        dpd_data[idx] = 0;
        dpx_data[idx] = 0;
        dpy_data[idx] = 0;
    }
}