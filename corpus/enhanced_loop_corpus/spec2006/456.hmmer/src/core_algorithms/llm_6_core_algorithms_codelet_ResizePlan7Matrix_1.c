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
    int j;
    for (i = 1; i <= N; i++) {
        j = i - 1;
        mx->xmx[i] = mx->xmx[j] + 5;
        mx->mmx[i] = mx->mmx[j] + (M + 2);
        mx->imx[i] = mx->imx[j] + (M + 2);
        mx->dmx[i] = mx->dmx[j] + (M + 2);
    }
}
