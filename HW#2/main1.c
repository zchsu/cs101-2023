#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 69
#define MAX_SPECIAL_NUM 10
#define NUM_OF_LOTTERY 6
#define NUM_OF_SPECIAL 1

void sort(int *arr, int length) {
    for (int k = 0; k < length-1; k++) {    
        for (int j = 0; j < length-k-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    } 
}
int check_same(int *arr, int num, int length) {
    for (int i = 0; i < length; i++) {
        if (arr[i] == num) {
            return 1;
        }
    }
    return 0;
}
void check_special_same(int *arr, int *arr_s, int max_special_num, int length) {
    for (int i = 0; i < length; i++) {
        if (arr[i] == arr_s[0]) {
            arr_s[0] = rand() % max_special_num + 1;
        }
    }
}
void generate_lottery_numbers(int *arr, int max_num, int length) {
    for (int i = 0; i < length; i++) {
        int num = rand() % max_num + 1;
        while (check_same(arr, num, i)) {
            num = rand() % max_num + 1;
        }
        arr[i] = num;
    }
}
int main() {
    int lottery_numbers[NUM_OF_LOTTERY], special_number[NUM_OF_SPECIAL], n;
    srand((unsigned)time(NULL));
    printf("歡迎光臨長庚樂透彩購買機臺\n請問您要買幾組樂透彩 (1 ~ 5): ");
    scanf("%d", &n);
    printf("以爲您購買的%d組樂透組合輸出至lotto.txt\n", n);
    FILE* fp = fopen("lotto.txt", "w+");
    putenv("TZ=Asia/Taipei");
    tzset();
    time_t curtime = time(NULL);
    asctime(localtime(&curtime));
    fprintf(fp, "======== lotto649 ========\n %s", asctime(localtime(&curtime)));
    for (int i = 1; i <= n; i++) {
        generate_lottery_numbers(lottery_numbers, MAX_NUM, NUM_OF_LOTTERY);
        generate_lottery_numbers(special_number, MAX_SPECIAL_NUM, NUM_OF_SPECIAL);
        sort(lottery_numbers, NUM_OF_LOTTERY);
        fprintf(fp, "[%d]: ", i);
        for (int i = 0; i < NUM_OF_LOTTERY; i++) {
            if(lottery_numbers[i] <= 9) {
                fprintf(fp, "0%d ", lottery_numbers[i]);
            } else {
                fprintf(fp, "%d ", lottery_numbers[i]);
            }
        }
        for (int i = 0; i < NUM_OF_SPECIAL; i++) { 
            check_special_same(lottery_numbers, special_number, MAX_SPECIAL_NUM, NUM_OF_LOTTERY);
            if(special_number[i] <= 9) {
                fprintf(fp, "0%d ", special_number[i]);
            } else {
                fprintf(fp, "%d ", special_number[i]);
            }   
        }
        fprintf(fp, "\n");
    }
    for (int i = n+1; i <= 5; i++) {
        fprintf(fp, "[%d]: -- -- -- -- -- -- --\n", i);
    }
    fprintf(fp, "======== csie@CGU ========\n");
    fclose(fp);
    return 0;
}
