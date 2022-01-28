#include <stdio.h>
#define N 20

void add(int sum[], int a[], int b[]);
void add_dbl(int sum[], int a[], int b[]);
void mul(int prod[], int a[], int b[]);
void prn_num(int a[]);
void prn_dbl(int a[]);

int main(void) {
        int a[N] = {7,5,9,8,9,7,5,0,0,9,9,0,8,8};
        int b[N] = {7,7,5,3,1,2,8,8,9,6,7,7};
        int sum[N];

        printf("Integer a: ");
        prn_num(a);
        printf("Integer b: ");
        prn_num(b);
        add(sum, a, b);
        printf("      Sum: ");
        prn_num(sum);

        /* TESTING FOR ADD_DBL 
        int a2[2*N] = {7,5,9,8,9,7,5,0,0,9,9,0,8,8};
        int b2[2*N] = {7,7,5,3,1,2,8,8,9,6,7,7};
        int sumDbl[2*N];
        add_dbl(sumDbl, a2, b2);
        printf("Sum with add_dbl: ");
        prn_dbl(sumDbl);*/

        int c[N] = {1,6,4,5,3,4,7,6,4,8,9,0,2,2,5,8,6,4,6};
        int d[N] = {9,3,5,4,6,5,2,3,5,1,0,9,7,7,4,1,3,5,3};
        int sum2[N];

        printf("\nInteger c: ");
        prn_num(c);
        printf("Integer d: ");
        prn_num(d);
        add(sum2, c, d);
        printf("      Sum: ");
        prn_num(sum2);

        int prod[2*N];

        printf("\nInteger a: ");
        prn_num(a);
        printf("Integer b: ");
        prn_num(b);
        mul(prod, a, b);
        printf("Product: ");
        prn_dbl(prod);
        return 0;
}

void prn_num(int a[]) {
        int i;
        for(i = N-1; i >= 0; --i) {
                if(a[i] == 0) putchar(' ');
                else break;
        }
        for(; i >= 0; --i) printf("%d", a[i]);
        putchar('\n');
}

void prn_dbl(int a[]) {
        int i;
        for(i = 2*N-1; i >= 0; --i) {
                if(a[i] == 0) putchar(' ');
                else break;
        }
        for(; i >= 0; --i) printf("%d", a[i]);
        putchar('\n');
}

void mul(int prod[], int a[], int b[]) {
        int i;
        for(i = 0; i < 2*N; i++) {
                prod[i] = 0;
        }
        int j;
        for(i = 0; i < N; i++) {
                for(j = 0; j < N; j++) {
                        prod[i+j] += (a[i]*b[j])%10;
                        if(prod[i+j] >= 10) {
                                prod[i+j]%=10;
                                prod[i+j+1]++;
                        }
                        prod[i+j+1] += (a[i]*b[j])/10;
                        if(prod[i+j+1] >= 10) {
                                prod[i+j+1]%=10;
                                prod[i+j+2]++;
                        }
                }
        }
}

void add_dbl(int sum[], int a[], int b[]) {
        int carry = 0;
        int i;
        for(i = 0; i < 2*N; i++) {
                sum[i] = (a[i] + b[i] + carry)%10;
                carry = (a[i] + b[i] + carry)/10;
        }
}

void add(int sum[], int a[], int b[]) {
        int carry = 0;
        int i;
        for(i = 0; i < N; i++) {
                sum[i] = (a[i] + b[i] + carry)%10;
                carry = (a[i] + b[i] + carry)/10;
        }
}
