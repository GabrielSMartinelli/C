#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
    char* num = (char*)calloc(1001, sizeof(char));
    int i, freq[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    
    scanf("%s", num);

    for(i=0;i<strlen(num);i++) {
        char str[2];
        str[0] = num[i];
        float x = atof(str);
        if(isnan(x) == 0) {
            freq[num[i]-'0'] += 1;
        }
    }
    
    for(i=0;i<10;i++) {
        printf("%d ", freq[i]);
    }
    return 0;
}