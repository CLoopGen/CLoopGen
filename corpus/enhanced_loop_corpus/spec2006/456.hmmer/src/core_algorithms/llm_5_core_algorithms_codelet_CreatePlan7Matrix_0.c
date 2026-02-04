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
for (i = 1; i <= N; i++) {
    if (i > N / 2) {
        mx->xmx[i] = mx->xmx[0] + (i * 5);
        mx->mmx[i] = mx->mmx[0] + (i * (M + 2));
        mx->imx[i] = mx->imx[0] + (i * (M + 2));
        mx->dmx[i] = mx->dmx[0] + (i * (M + 2));
    } else {
        mx->xmx[i] = mx->xmx[0];
        mx->mmx[i] = mx->mmx[0];
        mx->imx[i] = mx->imx[0];
        mx->dmx[i] = mx->dmx[0];
    }
}
}
