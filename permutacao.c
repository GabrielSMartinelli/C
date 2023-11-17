#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int next_permutation(int n, char **s)
{
    int i, j, k, l, mmp;
    char *aux = calloc(11, sizeof(char));
    for(i=n-2;i>=0;i--) {
        mmp = i + 1;
        //encontra o maior mais proximo
        for(j=i+2;j<n;j++) {
            if(strcmp(s[j], s[i]) > 0 && strcmp(s[j], s[mmp]) <= 0) {
                mmp = j;
            }
        }
        //troca com o maior mais proximo
        if(strcmp(s[i], s[mmp]) < 0) {
            aux = s[i];
            s[i] = s[mmp];
            s[mmp] = aux;
            //reordena os termos apos i
            l = n-1;
            for(k=i+1;k<(n+i+1)/2;k++) {
                aux = s[k];
                s[k] = s[l];
                s[l] = aux;
                l--;
            }
            i = n-2;
            return 1;
        }
    }
    
    return 0;
}

int main()
{
	char **s;
	int n;
	scanf("%d", &n);
	s = calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		s[i] = calloc(11, sizeof(char));
		scanf("%s", s[i]);
	}
	do
	{
		for (int i = 0; i < n; i++)
			printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
	} while (next_permutation(n, s));
	for (int i = 0; i < n; i++)
		free(s[i]);
	free(s);
	return 0;
}