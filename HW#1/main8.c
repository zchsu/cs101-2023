#include <stdio.h>

int main() {
    char a[] = "10001111";
    char str[100];
    int decimal = 0;
    
    int i, j;
    for(i = 0; a[i] != '\0'; i++) {     //轉十進位
        decimal = decimal * 2 + (a[i] - '0');
    }
    i = 0;
    
    while (decimal != 0) {    //計算十六進位
        int r = decimal % 16;
        str[i++] = (r < 10)?r + '0':r - 10 + 'A';
        decimal /= 16;
    }
    if (i == 0) {
        str[i++] = '0';
    }
    str[i] = '\0';
    
    int len = i;
    for (i = 0, j = len - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
    printf("%s\n", str);
    return 0;
}
