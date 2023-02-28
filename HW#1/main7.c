#include <stdio.h>

int main() {
    char a[] = "10001111";
    char str[100];
    int decimal = 0;
    int len = (sizeof(a) / sizeof(char) - 1) / 4;
    
    int i, j;
    for (i = 0; a[i] != '\0'; i++) {     //轉十進位
        decimal = decimal * 2 + (a[i] - '0');
    }
    if (decimal == 0) {   //如果輸入為00000000
        printf("%d", decimal);
    }

    while (decimal != 0) {    //計算十六進位
        int r = decimal % 16;   
        str[len - 1] = (r < 10)?r + '0':r - 10 + 'A';
        decimal /= 16;
        len--;
    }  
    printf("%s\n", str);
    return 0;
}
