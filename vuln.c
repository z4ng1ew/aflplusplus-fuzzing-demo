#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void crash(char *input) {
    char buffer[100];
    strcpy(buffer, input);  // здесь возможен буферный переполнение
    printf("Вы ввели: %s\n", buffer);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Использование: %s <строка>\n", argv[0]);
        return 1;
    }
    crash(argv[1]);
    return 0;
}
