#include <stdio.h>

#include <inttypes.h>

struct dpmatrix_s {
    int **xmx;
    int **mmx;
    int **imx;
    int **dmx;
    void *xmx_mem;
    void *mmx_mem;
    void *imx_mem;
    void *dmx_mem;
    int maxN;
    int maxM;
    int padN;
    int padM;
};


extern int N;
extern int M;
extern struct dpmatrix_s *mx;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic unrolling
    int *xmx_base = mx->xmx[0];
    int *mmx_base = mx->mmx[0];
    int *imx_base = mx->imx[0];
    int *dmx_base = mx->dmx[0];
    const int x_stride = 5;
    const int m_stride = M + 2;

    for (i = 1; i <= N; i++) {
        int offset_x = i * x_stride;
        int offset_m = i * m_stride;
        mx->xmx[i] = xmx_base + offset_x;
        mx->mmx[i] = mmx_base + offset_m;
        mx->imx[i] = imx_base + offset_m;
        mx->dmx[i] = dmx_base + offset_m;
    }
}
