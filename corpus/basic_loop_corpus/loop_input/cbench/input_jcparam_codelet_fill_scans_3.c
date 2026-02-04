#include <stdio.h>
#include <inttypes.h>

typedef struct {
    int comps_in_scan;
    int component_index[4];
    int Ss;
    int Se;
    int Ah;
    int Al;
} jpeg_scan_info;

jpeg_scan_info *scanptr;
int ncomps;
int Ss;
int Se;
int Ah;
int Al;
int ci;

#define DATA_SIZE (128 << 20)  // 128 MB of data

static jpeg_scan_info scan_buffer[DATA_SIZE / sizeof(jpeg_scan_info)];

void init_vars() {
    scanptr = scan_buffer;
    ncomps = sizeof(scan_buffer) / sizeof(jpeg_scan_info);
    Ss = 1;
    Se = 63;
    Ah = 0;
    Al = 0;
    ci = 0;
}