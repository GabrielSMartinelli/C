#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lexicographic_sort(const char* a, const char* b) {
    if(strcmp(a, b) <= 0) {return 1;}
    return 0;
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    if(strcmp(a, b) >= 0) {return 1;}
    return 0;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int i, j, tam1, tam2;
    char* distinct = (char*)calloc(1, sizeof(char));
    for(i=0;i<strlen(a);i++) {
        tam1 = strlen(distinct);
        j = 0;
        while(a[i]!=distinct[j] && j<tam1) {
            j++;
        }
        if(j == tam1) {
            distinct = (char*)realloc(distinct, (tam1+2)*sizeof(char));
            distinct[tam1] = a[i];
            distinct[tam1+1] = '\0';
            if(i == strlen(a)-1)
                tam1 += 1;
        }
    }
    free(distinct);
    distinct = (char*)calloc(1, sizeof(char));
    
    for(i=0;i<strlen(b);i++) {
        tam2 = strlen(distinct);
        j = 0;
        while(b[i]!=distinct[j] && j<tam2) {
            j++;
        }
        if(j == tam2) {
            distinct = (char*)realloc(distinct, (tam2+2)*sizeof(char));
            distinct[tam2] = b[i];
            distinct[tam2+1] = '\0';
            if(i == strlen(b)-1)
                tam2 += 1;
        }
    }
    free(distinct);
    
    if(tam1 < tam2) {return 1;}
    else if(tam1 == tam2) {
        if(strcmp(a, b) <= 0) {return 1;}
        else {return 0;}
    }
    return 0;
}

int sort_by_length(const char* a, const char* b) {
    int tam1, tam2;
    tam1 = strlen(a);
    tam2 = strlen(b);
    if(tam1 < tam2) {return 1;}
    else if(tam1 == tam2) {
        if(strcmp(a, b) <= 0) {return 1;}
        else {return 0;}
    }
    return 0;
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    char* aux = (char*)calloc(2500, sizeof(char));
    for(int i=0;i<len-1;i++) {
        for(int j=i+1;j<len;j++) {
            if(cmp_func(arr[i], arr[j]) == 0) {
                aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
            }
        }
    }
}


int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}