#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;
void sort_by_area(triangle* tr, int n) {
	triangle aux;
    int i, j;
    double* area = (double*)calloc(n, sizeof(double));
    double p, sub;
    for(i=0;i<n;i++) {
        p = (tr[i].a + tr[i].b + tr[i].c)/2.0;
        area[i] = sqrt(p*(p-tr[i].a)*(p-tr[i].b)*(p-tr[i].c));
        printf("%lf\n", area[i]);
    }
    for(i=0;i<n-1;i++) {
        for(j=i+1;j<n;j++){
            if(area[i] > area[j]) {
                sub = area[i];
                area[i] = area[j];
                area[j] = sub;
                aux = tr[i];
                tr[i] = tr[j];
                tr[j] = aux;
            }
        }
    }
    free(area);
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}
