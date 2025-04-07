#include <stdio.h>

int my_atoi(const char* str) {
    int num = 0;
    int i = 0;
    while (str[i] >= '0' && str[i] <= '9') {
        num = num * 10 + (str[i] - '0');
        i++;
    }
    return num;
}

int main() {
    FILE* file = NULL;
    errno_t err = fopen_s(&file, "in.txt", "r");
    if (err != 0 || file == NULL) {
        printf("Failed to open in.txt\n");
        return 1;
    }

    char buffer[1024];

    while (fgets(buffer, sizeof(buffer), file)) {
        int lineSum = 0;
        char* ptr = buffer;

        while (*ptr != '\0') {
            while (*ptr == ' ') ptr++;

            char numStr[32];
            int i = 0;
            while (*ptr >= '0' && *ptr <= '9') {
                numStr[i++] = *ptr;
                ptr++;
            }
            numStr[i] = '\0';

            if (i > 0)
                lineSum += my_atoi(numStr);
            else if (*ptr != '\0')
                ptr++;
        }

        printf("%d\n", lineSum);
    }

    fclose(file);
    return 0;
}
