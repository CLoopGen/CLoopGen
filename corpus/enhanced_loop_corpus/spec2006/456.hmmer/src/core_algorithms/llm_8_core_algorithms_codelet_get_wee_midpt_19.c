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
        sc = fwd->mmx[cur][k] + bck->mmx[cur][k];
        if (sc > max) {
            max = sc;
            k2 = k;
            t2 = 1;
        }
        if (k + 1 <= k3) {
            sc = fwd->imx[cur][k + 1] + bck->imx[cur][k + 1];
            if (sc > max) {
                max = sc;
                k2 = k + 1;
                t2 = 3;
            }
        }
    }
}
