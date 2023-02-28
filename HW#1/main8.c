#include <stdio.h>

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(char str[], int len) {
    int i, j;
    for (i = 0, j = len-1; i < j; i++, j--) {    // 交換字母
        
        while (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) && i < j) i++;
        while (!((str[j] >= 'a' && str[j] <= 'z') || (str[j] >= 'A' && str[j] <= 'Z')) && i < j) j--;
        swap(&str[i], &str[j]);
    }
}

void to_upper_case(char str[], int len) {
    if (str[0] >= 'a' && str[0] <= 'z') {
            str[0] = str[0] - 'a' + 'A';
    }
    if (str[len - 2] >= 'A' && str[len - 2] <= 'Z') {
            str[len - 2] = str[len - 2] - 'A' + 'a';
    }
}

int main() {
    char a[] = "Hello";
    int len = sizeof(a) / sizeof(a[0]);
    printf("a: %s\n", a);
    reverse(a, len);
    to_upper_case(a, len);
    printf("a: %s\n", a);
    return 0;
}
