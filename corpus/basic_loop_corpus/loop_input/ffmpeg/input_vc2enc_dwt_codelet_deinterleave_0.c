#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int32_t dwtcoef;

dwtcoef *linell;
ptrdiff_t stride;
int width;
int height;
dwtcoef *synthl;
int x;
int y;
ptrdiff_t synthw;
dwtcoef *linehl;
dwtcoef *linelh;
dwtcoef *linehh;

static dwtcoef *linell_data;
static dwtcoef *synthl_data;
static dwtcoef *linehl_data;
static dwtcoef *linelh_data;
static dwtcoef *linehh_data;

void init_vars() {
    width = 2048;
    height = 256;
    synthw = width * 2;
    stride = width;

    size_t total_synthl_size = height * 2 * synthw;
    size_t total_output_size = height * stride;

    synthl_data = (dwtcoef*)calloc(total_synthl_size, sizeof(dwtcoef));
    linell_data = (dwtcoef*)calloc(total_output_size, sizeof(dwtcoef));
    linehl_data = (dwtcoef*)calloc(total_output_size, sizeof(dwtcoef));
    linelh_data = (dwtcoef*)calloc(total_output_size, sizeof(dwtcoef));
    linehh_data = (dwtcoef*)calloc(total_output_size, sizeof(dwtcoef));

    if (!synthl_data || !linell_data || !linehl_data || !linelh_data || !linehh_data) {
        exit(1);
    }

    synthl = synthl_data;
    linell = linell_data;
    linehl = linehl_data;
    linelh = linelh_data;
    linehh = linehh_data;
}