#include <stdio.h>

#include <inttypes.h>

typedef unsigned char uchar;

extern uchar *in;
extern int *r;
extern uchar *bp;
extern int max_no;
extern int x_size;
extern int y_size;
extern int i;
extern int j;
extern int n;
extern uchar *p;
extern uchar *cp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Eliminate pointer arithmetic accumulation to break artificial RAW/WAR dependencies
    // Unroll inner loop partially and reorganize memory accesses to expose parallelism
    for (i = 3; i < y_size - 3; i += 2) {  // Increase stride to reduce loop-carried dependence frequency
        for (j = 3; j < x_size - 3; j += 2) {
            // Process two elements at once to decouple dependencies
            int indices[4];
            uchar* ptrs[4];
            int ns[4];
            int valid[4] = {0};

            int count = 0;
            for (int di = 0; di < 2; di++) {
                for (int dj = 0; dj < 2; dj++) {
                    int ii = i + di, jj = j + dj;
                    if (ii >= y_size - 3 || jj >= x_size - 3) continue;
                    indices[count] = ii * x_size + jj;
                    ptrs[count] = in + (ii - 3) * x_size + jj - 1;
                    ns[count] = 100;
                    cp = bp + in[indices[count]];
                    
                    // Replicate the original access pattern without relying on post-increment side effects
                    uchar* temp_p = ptrs[count];
                    ns[count] += *(cp - temp_p[0]); temp_p++;
                    ns[count] += *(cp - temp_p[0]); temp_p++;
                    ns[count] += *(cp - temp_p[0]);
                    temp_p += x_size - 3;
                    ns[count] += *(cp - temp_p[0]); temp_p++;
                    ns[count] += *(cp - temp_p[0]); temp_p++;
                    ns[count] += *(cp - temp_p[0]); temp_p++;
                    ns[count] += *(cp - temp_p[0]); temp_p++;
                    ns[count] += *(cp - temp_p[0]);
                    temp_p += x_size - 5;
                    ns[count] += *(cp - temp_p[0]); temp_p++;
                    ns[count] += *(cp - temp_p[0]); temp_p++;
                    ns[count] += *(cp - temp_p[0]); temp_p++;
                    ns[count] += *(cp - temp_p[0]); temp_p++;
                    ns[count] += *(cp - temp_p[0]); temp_p++;
                    ns[count] += *(cp - temp_p[0]); temp_p++;
                    ns[count] += *(cp - temp_p[0]);
                    temp_p += x_size - 6;
                    ns[count] += *(cp - temp_p[0]); temp_p++;
                    ns[count] += *(cp - temp_p[0]); temp_p++;
                    ns[count] += *(cp - temp_p[0]);
                    temp_p += 2;
                    ns[count] += *(cp - temp_p[0]); temp_p++;
                    ns[count] += *(cp - temp_p[0]); temp_p++;
                    ns[count] += *(cp - temp_p[0]);
                    temp_p += x_size - 6;
                    ns[count] += *(cp - temp_p[0]); temp_p++;
                    ns[count] += *(cp - temp_p[0]); temp_p++;
                    ns[count] += *(cp - temp_p[0]); temp_p++;
                    ns[count] += *(cp - temp_p[0]); temp_p++;
                    ns[count] += *(cp - temp_p[0]); temp_p++;
                    ns[count] += *(cp - temp_p[0]); temp_p++;
                    ns[count] += *(cp - temp_p[0]);
                    temp_p += x_size - 5;
                    ns[count] += *(cp - temp_p[0]); temp_p++;
                    ns[count] += *(cp - temp_p[0]); temp_p++;
                    ns[count] += *(cp - temp_p[0]); temp_p++;
                    ns[count] += *(cp - temp_p[0]); temp_p++;
                    ns[count] += *(cp - temp_p[0]);
                    temp_p += x_size - 3;
                    ns[count] += *(cp - temp_p[0]); temp_p++;
                    ns[count] += *(cp - temp_p[0]); temp_p++;
                    ns[count] += *(cp - temp_p[0]);

                    if (ns[count] <= max_no)
                        valid[count] = 1;

                    count++;
                }
            }

            // Write results independently — no sequential dependence
            for (int k = 0; k < count; k++) {
                if (valid[k]) {
                    r[indices[k]] = max_no - ns[k];
                }
            }
        }
    }
}
