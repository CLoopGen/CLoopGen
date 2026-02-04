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


extern struct dpmatrix_s *mx;
extern int N;
extern int M;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 2;
    for (i = 1; i <= N; i += step) {
        mx->xmx[i] = mx->xmx[0] + (i * 5);
        if (i + 1 <= N) {
            mx->xmx[i + 1] = mx->xmx[0] + ((i + 1) * 5);
        }
        mx->mmx[i] = mx->mmx[0] + (i * (M + 2));
        mx->imx[i] = mx->imx[0] + (i * (M + 2));
        mx->dmx[i] = mx->dmx[0] + (i * (M + 2));
        if (i + 1 <= N) {
            mx->mmx[i + 1] = mx->mmx[0] + ((i + 1) * (M + 2));
            mx->imx[i + 1] = mx->imx[0] + ((i + 1) * (M + 2));
            mx->dmx[i + 1] = mx->dmx[0] + ((i + 1) * (M + 2));
        }
    }
}
