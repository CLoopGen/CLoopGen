#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

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

void init_vars() {
    Ss = 0;
    Se = 63;
    Ah = 0;
    Al = 0;
    ncomps = 1000000; // Adjusted to ensure loop runs ~0.01 seconds

    jpeg_scan_info *scan_array = (jpeg_scan_info*)calloc(ncomps, sizeof(jpeg_scan_info));
    if (!scan_array) exit(1);

    scanptr = scan_array;
}