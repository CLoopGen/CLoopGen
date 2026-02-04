#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

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
    ncomps = 5000000;  // Adjusted to achieve ~0.01 sec runtime

    Ss = 10;
    Se = 50;
    Ah = 2;
    Al = 3;
    ci = 0;

    jpeg_scan_info *scan_array = (jpeg_scan_info *)calloc(ncomps, sizeof(jpeg_scan_info));
    if (!scan_array) {
        exit(1);
    }

    scanptr = scan_array;
}