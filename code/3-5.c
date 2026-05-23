#include <stdio.h>

int main(int argc, const char* argv[]) {
    const char* filename = "numbers.txt";

    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        return 0;
    }

    char line[256];
    int sum = 0;

    while (fgets(line, sizeof(line), fp) != NULL) {
        char* endptr;
        long val = strtol(line, &endptr, 10);

        if (endptr == line || (*endptr != '\n' && *endptr != '\0')) {
            line[strcspn(line, "\n")] = '\0';
            fprintf(stderr, "invalid input %s\n", line);
        }
        else {
            sum += (int)val;
        }
    }


    printf("sum: %d\n", sum);
    fclose(fp);
    return 0;
}
