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
    double m20 = M20[c];
    double m02 = M02[c];
    double m11 = M11[c];
    double m30 = M30[c];
    double m12 = M12[c];
    double m21 = M21[c];
    double m03 = M03[c];

    double temp1 = m20 + m02;
    double temp2 = m20 - m02;
    double temp3 = m30 - 3.0 * m12;
    double temp4 = 3.0 * m21 - m03;
    double temp5 = m30 + m12;
    double temp6 = m21 + m03;

    channel_moments[c].invariant[0] = temp1;
    channel_moments[c].invariant[1] = temp2 * temp2 + 4.0 * m11 * m11;
    channel_moments[c].invariant[2] = temp3 * temp3 + temp4 * temp4;
    channel_moments[c].invariant[3] = temp5 * temp5 + temp6 * temp6;

    double temp7 = temp5 * temp5 - 3.0 * temp6 * temp6;
    double temp8 = 3.0 * temp5 * temp5 - temp6 * temp6;

    channel_moments[c].invariant[4] = temp3 * temp5 * temp7 + temp4 * temp6 * temp8;
    channel_moments[c].invariant[5] = temp2 * (temp5 * temp5 - temp6 * temp6) + 4.0 * m11 * temp5 * temp6;

    double temp9 = temp5 * temp5 - 3.0 * temp6 * temp6;
    double temp10 = 3.0 * temp5 * temp5 - temp6 * temp6;

    channel_moments[c].invariant[6] = temp4 * temp5 * temp9 - temp3 * temp6 * temp10;
    channel_moments[c].invariant[7] = m11 * (temp5 * temp5 - temp6 * temp6) - temp2 * temp5 * temp6;
}
}
