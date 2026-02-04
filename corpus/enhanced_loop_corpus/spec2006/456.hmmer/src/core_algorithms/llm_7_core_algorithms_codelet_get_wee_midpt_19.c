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
        int sc1 = -1, sc2 = -1;
        int update1 = 0, update2 = 0;
        int temp_k2_1 = k2;
        int temp_k2_3 = k2;
        char temp_t2_1 = t2;
        char temp_t2_3 = t2;

        if (k <= k3) {
            sc1 = fwd->mmx[cur][k] + bck->mmx[cur][k];
            update1 = (sc1 > max);
            if (update1) {
                temp_k2_1 = k;
                temp_t2_1 = 1;
                max = sc1;
            }
        }

        if (k + 1 <= k3) {
            sc2 = fwd->imx[cur][k + 1] + bck->imx[cur][k + 1];
            update2 = (sc2 > max);
            if (update2) {
                temp_k2_3 = k + 1;
                temp_t2_3 = 3;
                max = sc2;
            }
        }

        if (update1 && (!update2 || sc1 >= sc2)) {
            k2 = temp_k2_1;
            t2 = temp_t2_1;
        } else if (update2) {
            k2 = temp_k2_3;
            t2 = temp_t2_3;
        }
    }
}
