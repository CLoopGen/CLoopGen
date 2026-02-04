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
    int base_xmx = 0;
    int base_mmx = 0;
    int base_imx = 0;
    int base_dmx = 0;
    for (i = 1; i <= N; i++) {
        base_xmx += 5;
        base_mmx += (M + 2);
        base_imx += (M + 2);
        base_dmx += (M + 2);
        mx->xmx[i] = mx->xmx[0] + base_xmx;
        mx->mmx[i] = mx->mmx[0] + base_mmx;
        mx->imx[i] = mx->imx[0] + base_imx;
        mx->dmx[i] = mx->dmx[0] + base_dmx;
    }
}
