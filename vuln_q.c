#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char buffer[8];
    FILE *f = fopen(argv[1], "r");
    if (!f) return 1;

    fgets(buffer, 128, f);  // <-- Переполнение буфера!
    fclose(f);

    printf("Got: %s\n", buffer);
    return 0;
}

