#include <stdio.h>
#include <string.h>

int main() {
    char password[100];
    int length = 0;
    int has_lower = 0;
    int has_upper = 0;
    int has_digit = 0;
    int has_special = 0;
    int i = 0;

    printf("请输入密码：");
    scanf("%s", password);

    length = strlen(password);

    // 逐个检查字符
    while (password[i] != '\0') {
        if (password[i] >= 'a' && password[i] <= 'z') {
            has_lower = 1;
        } else if (password[i] >= 'A' && password[i] <= 'Z') {
            has_upper = 1;
        } else if (password[i] >= '0' && password[i] <= '9') {
            has_digit = 1;
        } else {
            has_special = 1;
        }
        i++;
    }

    // 开始根据长度和种类判断
    if (length < 6) {
        printf("密码强度：弱（太短啦！）\n");
    } else {
        int kind = has_lower + has_upper + has_digit + has_special;
        if (length >= 8 && kind >= 3) {
            printf("密码强度：强（棒棒哒！）\n");
        } else if (kind >= 2) {
            printf("密码强度：中（可以更好！）\n");
        } else {
            printf("密码强度：弱（需要改进哦～）\n");
        }
    }

    // 小提示
    if (!has_special) {
        printf("提示：加入特殊符号可以提升安全性哦！\n");
    }
    if (length < 10) {
        printf("提示：密码长度最好超过10位！\n");
    }

    return 0;
}
