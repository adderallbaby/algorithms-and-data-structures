#include <stdio.h>
int binor(x,y){
    int u;
    u = x | y;
    return u;
}
int binoffset(n){
    int u;
    u = 1 << n;
    return u;
}
int main()
{
    unsigned int  z;
    unsigned int x,y;
    int a,b,i,q;
    int f,n;
    int ff,nn;
    f = ff = 0;
    y = 0;

    i = 0;
    x = 0;
    scanf ("%d\n", &b);
    for (i = 0; i < b; i++) {
        scanf ("%d",&nn);
        ff= binor(ff, binoffset(nn));
        x= binor(ff, x);
    }
    scanf ("%d\n", &a);
    for (i = 0; i < a; i++) {
        scanf("%d",&n);
        f= binor(f,  binoffset(n));
        y= binor(f ,y);
    }
    z = x & y;
    q = 0;
    while (z > 0) {
        if (z & 1)
            printf ("%d ", q);
        q += 1;
        z = z >> 1;
    }
    return 0;
}