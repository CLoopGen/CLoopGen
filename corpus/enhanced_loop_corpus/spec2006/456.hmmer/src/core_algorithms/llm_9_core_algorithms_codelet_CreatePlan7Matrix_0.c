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
    for (i = 2; i <= N; i++) {
        int stride_x = 5;
        int stride_m = M + 2;
        mx->xmx[i] = mx->xmx[0] + (i * stride_x);
        mx->mmx[i] = mx->mmx[0] + (i * stride_m);
        mx->imx[i] = mx->imx[0] + (i * stride_m);
        mx->dmx[i] = mx->dmx[0] + (i * stride_m);

        mx->xmx[i-1] = mx->xmx[0] + ((i - 1) * stride_x);
        mx->mmx[i-1] = mx->mmx[0] + ((i - 1) * stride_m);
        mx->imx[i-1] = mx->imx[0] + ((i - 1) * stride_m);
        mx->dmx[i-1] = mx->dmx[0] + ((i - 1) * stride_m);
    }

    if (N >= 1) {
        mx->xmx[1] = mx->xmx[0] + (1 * 5);
        mx->mmx[1] = mx->mmx[0] + (1 * (M + 2));
        mx->imx[1] = mx->imx[0] + (1 * (M + 2));
        mx->dmx[1] = mx->dmx[0] + (1 * (M + 2));
    }
}
