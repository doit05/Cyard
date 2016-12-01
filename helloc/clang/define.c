#include <stdio.h>
#ifndef SYMBOL
#define  N 3
#define Y(n)((N+1)*n)
#endif

struct str

{  int x:3;

   int y:4;

   int z:5;
   double a;

};

int main(int argc, char const *argv[]) {
    int z = 2*(N + Y(5+1));
    printf("%d\n%d\n", z, Y(5+1));
    struct str *s;
    int size = sizeof(s);
    printf("%d\n",size );
    return 0;
}
