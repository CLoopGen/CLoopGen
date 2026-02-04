#include <stdio.h>
#include <inttypes.h>

int Ncolors[65536];
int nc = 65536;
int total_colors = 1;
int iroot = 2;
int i;

void init_vars() {
    total_colors = 1;
    iroot = 2;
    nc = 65536;
}