#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define HDIM 225
#define VDIM 80
#define DIST 25
#define SCALE 50
#define ZP 5
#define YTRANS 0
#define RMOVE 65
#define DMOVE -65

#define X ((1/y) * sin(t))
#define Y (y)
#define Z ((1/y) * cos(t))
#define XR X
#define YR ( (Y * cos(p)) - (Z * sin(p)) )
#define ZR ( (Y * sin(p)) + (Z * cos(p)) + DIST)

void plot(char[VDIM][HDIM]);

void empty(char[VDIM][HDIM]);

int main(int argc, char **argv)
{
    int xoff = HDIM / 2;
    int yoff = VDIM / 2;
    char output[VDIM][HDIM];
    empty(output);
    float p = 0.0;
    while(1)
    {
        for(float y = 1.0; y <= 4; y += 0.02) // will need to lower the max y from 8 to properly rotate later
        {
            for(float t = 0.0; t <= 6.28; t += 0.02)
            {
                double xproj = ZP * XR * SCALE / ZR;
                double yproj = ZP * YR * 2.25 * SCALE / ZR; // SCALE * 2 to compensate for more vertical space than horizontal
                int xtrunc = xproj;
                int ytrunc = yproj;
                output[xoff - xtrunc + DMOVE][yoff + ytrunc + RMOVE] = '.'; // subtracted constants in matrices meant to fit in frame better
            }
        }
        p += 0.02;
        if(p >= 6.28) p = 0;
        system("clear");
        plot(output);
        empty(output);
    }
}

void plot(char out[VDIM][HDIM])
{
    for(int x = 0; x < VDIM; x++)
    {
        for(int y = 0; y < HDIM; y++)
        {
            printf("%c", out[x][y]);
        }
        printf("\n");
    }
}

void empty(char out[VDIM][HDIM])
{
    memset(out, ' ', HDIM * VDIM * sizeof(char));
}
