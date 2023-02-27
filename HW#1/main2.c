#include <stdio.h>

int main() {
    char a[] = "A3B2C4A9"; 
    char output[100];       // 放新字串的陣列
    int i = 0, j = 0;
    
    while (a[i] != '\0') {
        char alp = a[i];
        i++;
        int count = 0;
        while (a[i] >= '0' && a[i] <= '9') {
            count = a[i] - '0';
            i++;
            for (int k = 0; k < count; k++) {
            output[j] = alp;
            j++;
            }
        }
    }
    output[j] = '\0'; 
    printf("%s", output);
    
    return 0;
}
