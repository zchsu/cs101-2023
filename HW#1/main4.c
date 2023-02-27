#include <stdio.h>

int main() {
    char str[] = "ac-99bc";
    int i = 0, sign = 1, num = 0;
    
    while (str[i] != '\0') {
        if (str[i] == '-') {  // 檢查負號
            sign = -1;
        }
        i++;
    }    
    i=0;
    
    while (str[i] != '\0') {  
        if (str[i] >= '0' && str[i] <= '9') {  
            num = num * 10 + (str[i] - '0');  // 計算整數
        } 
        i++;
    }
    printf("%d\n", sign * num); 
    return 0;
}
