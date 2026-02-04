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
for (k = k1; k <= k3; k++) {
    int mmx_sc = fwd->mmx[cur][k] + bck->mmx[cur][k];
    int imx_sc = fwd->imx[cur][k] + bck->imx[cur][k];

    if (mmx_sc > max || imx_sc > max) {
        if (mmx_sc > imx_sc) {
            sc = mmx_sc;
            k2 = k;
            t2 = 1;
            max = sc;
        } else {
            sc = imx_sc;
            k2 = k;
            t2 = 3;
            max = sc;
        }
    }
}
}
