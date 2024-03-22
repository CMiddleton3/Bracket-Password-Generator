#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 20

char generate_random_char() {
    const char charset[] = "abcdefghijklmnopqrstuvwxyz0123456789";
    return charset[rand() % (sizeof(charset) - 1)];
}

char generate_random_special_char() {
    const char special_chars[] = "!@#$%^&*()";
    return special_chars[rand() % (sizeof(special_chars) - 1)];
}

void generate_random_password(char *password) {
    int i;
    for (i = 0; i < PASSWORD_LENGTH; ++i) {
        if (i < 4 || (i >= 5 && i < 8) || (i >= 9 && i < 14) || (i >= 15 && i < 17)) {
            password[i] = generate_random_char();
        } else if (i == 4 || i == 8 || i == 14 || i == 17) {
            password[i] = '-';
        } else {
            password[i] = generate_random_special_char();
        }
    }
    password[PASSWORD_LENGTH] = '\0';
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <num_passwords>\n", argv[0]);
        return 1;
    }

    int num_passwords = atoi(argv[1]);
    if (num_passwords <= 0) {
        printf("Please provide a positive integer for the number of passwords.\n");
        return 1;
    }

    srand(time(NULL));

    int i;
    for (i = 0; i < num_passwords; ++i) {
        char password[PASSWORD_LENGTH + 1];
        generate_random_password(password);
        printf("%s\n", password);
    }

    return 0;
}

