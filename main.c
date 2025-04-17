#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <regex.h>

// 检查密码强度
int check_password_strength(const char* password) {
    int length = strlen(password);
    int has_lower = 0, has_upper = 0, has_digit = 0, has_special = 0;

    // 判断密码字符是否符合要求
    for (int i = 0; i < length; i++) {
        if (islower(password[i])) has_lower = 1;
        else if (isupper(password[i])) has_upper = 1;
        else if (isdigit(password[i])) has_digit = 1;
        else if (ispunct(password[i])) has_special = 1;
    }

    // 根据密码的复杂度返回强度
    if (length < 6) return 1; // 弱
    if (length >= 6 && length < 8) {
        if (has_lower && has_digit) return 2; // 中
        return 1;
    }
    if (has_lower && has_upper && has_digit && has_special) return 3; // 强
    return 2; // 中
}

// 输出密码强度
void print_strength(int strength) {
    switch (strength) {
        case 1: printf("密码强度：弱\n"); break;
        case 2: printf("密码强度：中\n"); break;
        case 3: printf("密码强度：强\n"); break;
        default: printf("无法评估密码强度\n"); break;
    }
}

int main() {
    char password[100];

    printf("请输入密码：");
    scanf("%99s", password); // 获取用户输入的密码

    int strength = check_password_strength(password);
    print_strength(strength); // 输出密码强度

    return 0;
}

