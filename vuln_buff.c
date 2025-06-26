#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char buffer[8];
    char input[128];

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *f = fopen(argv[1], "r");
    if (!f) {
        perror("fopen");
        return 1;
    }

    // Чтение строки из файла
    if (fgets(input, sizeof(input), f) == NULL) {
        fprintf(stderr, "Error: Could not read from file or file is empty.\n");
        fclose(f);
        buffer[0] = '\0'; // Пустая строка
    } else {
        // Более безопасное копирование с использованием snprintf
        // Гарантирует завершение строки нулём
        snprintf(buffer, sizeof(buffer), "%s", input);
    }

    fclose(f);

    printf("Вы ввели: %s\n", buffer);

    return 0;
}
