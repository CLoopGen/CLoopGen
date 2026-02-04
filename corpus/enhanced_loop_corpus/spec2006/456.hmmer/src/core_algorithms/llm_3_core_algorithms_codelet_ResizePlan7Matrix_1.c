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
    // Variant 2: Strided memory access with reverse iteration to modify access pattern
    // Access rows in reverse order to create a backward strided memory traversal
    int stride_x = 5;
    int stride_m = M + 2;

    for (i = N; i >= 1; i--) {
        mx->xmx[i] = mx->xmx[0] + ((N - i + 1) * stride_x);     // Forward fill from base but in reverse loop
        mx->mmx[i] = mx->mmx[0] + ((N - i + 1) * stride_m);
        mx->imx[i] = mx->imx[0] + ((N - i + 1) * stride_m);
        mx->dmx[i] = mx->dmx[0] + ((N - i + 1) * stride_m);
    }
}
