#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int j;

static unsigned int Uo_data[1024 * 256];
static unsigned int Vo_data[1024 * 256];
static int U_data[1024 * 256];
static int V_data[1024 * 256];

unsigned int *Uo = Uo_data;
unsigned int *Vo = Vo_data;
int *U = U_data;
int *V = V_data;

int oUstride = 1;
int oVstride = 1;
int Ustride = 1;
int Vstride = 1;

void init_vars() {
    for (int idx = 0; idx < 1024 * 256; idx++) {
        Uo_data[idx] = (unsigned int)(idx * 31);
        Vo_data[idx] = (unsigned int)(idx * 73);
        U_data[idx] = 0;
        V_data[idx] = 0;
    }
}