#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct _PointInfo {
    double x;
    double y;
} PointInfo;

typedef struct _ChannelMoments {
    double invariant[9];
    PointInfo centroid;
    PointInfo ellipse_axis;
    double ellipse_angle;
    double ellipse_eccentricity;
    double ellipse_intensity;
} ChannelMoments;

extern ChannelMoments *channel_moments;
extern double M02[129];
extern double M03[129];
extern double M11[129];
extern double M12[129];
extern double M20[129];
extern double M21[129];
extern double M30[129];
extern ssize_t c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (c = 0; c <= 64; c++) {
    double temp1 = M30[c] + M12[c];
    double temp2 = M21[c] + M03[c];
    double diff_x = M20[c] - M02[c];
    double m11_sq = M11[c] * M11[c];

    channel_moments[c].invariant[0] = M20[c] + M02[c];
    channel_moments[c].invariant[1] = diff_x * diff_x + 4. * m11_sq;

    if (temp1 * temp1 + temp2 * temp2 > 1e-8) {
        channel_moments[c].invariant[2] = (M30[c] - 3. * M12[c]) * (M30[c] - 3. * M12[c]) + (3. * M21[c] - M03[c]) * (3. * M21[c] - M03[c]);
        channel_moments[c].invariant[3] = temp1 * temp1 + temp2 * temp2;
        channel_moments[c].invariant[4] = (M30[c] - 3. * M12[c]) * temp1 * (temp1 * temp1 - 3. * temp2 * temp2) +
                                          (3. * M21[c] - M03[c]) * temp2 * (3. * temp1 * temp1 - temp2 * temp2);
        channel_moments[c].invariant[5] = diff_x * (temp1 * temp1 - temp2 * temp2) + 4. * M11[c] * temp1 * temp2;
        channel_moments[c].invariant[6] = (3. * M21[c] - M03[c]) * temp1 * (temp1 * temp1 - 3. * temp2 * temp2) -
                                          (M30[c] - 3. * M12[c]) * temp2 * (3. * temp1 * temp1 - temp2 * temp2);
        channel_moments[c].invariant[7] = M11[c] * (temp1 * temp1 - temp2 * temp2) - diff_x * temp1 * temp2;
    } else {
        channel_moments[c].invariant[2] = 0.0;
        channel_moments[c].invariant[3] = 0.0;
        channel_moments[c].invariant[4] = 0.0;
        channel_moments[c].invariant[5] = 0.0;
        channel_moments[c].invariant[6] = 0.0;
        channel_moments[c].invariant[7] = 0.0;
    }
}
}
