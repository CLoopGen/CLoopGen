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


extern int k1;
extern int k3;
extern struct dpmatrix_s *fwd;
extern struct dpmatrix_s *bck;
extern int k2;
extern char t2;
extern int cur;
extern int k;
extern int sc;
extern int max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = k1; k <= k3; k += 2) {
    int fwd_val_m = fwd->mmx[cur][k] + bck->mmx[cur][k];
    int fwd_val_i = fwd->imx[cur][k] + bck->imx[cur][k];
    if (fwd_val_m > max) {
        k2 = k;
        t2 = 1;
        max = fwd_val_m;
    }
    if (fwd_val_i > max) {
        k2 = k;
        t2 = 3;
        max = fwd_val_i;
    }
}
}
