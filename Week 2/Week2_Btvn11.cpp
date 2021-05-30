#include<stdio.h>

void ReadInput(short*& poly, int& degree)
{
    scanf("%d", &degree);
    poly = new short[degree + 1];
    for (int i = 0; i <= degree; ++i)
    {
        scanf("%d", (poly + i));
    }
}

int MultiplyAndXor(short* poly1, short* poly2, int deg1, int deg2)
{
    int res = 0;
    int sum = 0;
    int deg = deg1 + deg2;
    int maxDeg = (deg1 > deg2) ? deg1 : deg2;
    int minDeg = (maxDeg == deg1) ? deg2 : deg1;
    short* polyMax = (maxDeg == deg1) ? poly1 : poly2;
    short* polyMin = (maxDeg == deg1) ? poly2 : poly1;

    for (int i = 0; i <= deg; ++i)
    {
        sum = 0;
        for (int j = 0; j <= i; ++j)
        {
            if (i - j <= minDeg && j <= maxDeg)
            {
                sum += (polyMax[j] * polyMin[i - j]);
            }
        }
        res ^= sum;
    }
    return res;
}

void FreeMem(short*& poly)
{
    delete[] poly;
    poly = NULL;
}

int main()
{
	printf("Le Trong Khanh - 20194082\n\n");
    int deg1;
    short* poly1 = NULL;
    ReadInput(poly1, deg1);

    int deg2;
    short* poly2 = NULL;
    ReadInput(poly2, deg2);

    printf("%d", MultiplyAndXor(poly1, poly2, deg1, deg2));

    FreeMem(poly1);
    FreeMem(poly2);

    return 0;
}
