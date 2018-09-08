// PAT Advanced Level Exercise 1001 - A + B format
// Language: C(C99)

#include <stdio.h>
#include <string.h>

int main() {
    int a, b;
    scanf("%d%d", &a, &b);

    long result = (long)a + b;

    if (result <= 999 && result >= -999) {
        printf("%ld", result);
        return 0;
    }

    char buffer[50];
    sprintf(buffer, "%ld", result);

    int length = strlen(buffer);
    int skip_count = length % 3;
    int cycle_count = 0;
    if (result < 0) {
        skip_count = (length - 1) % 3 + 1;
        if (skip_count == 1) { // a comma will follow a minus, like -,999,999
            cycle_count = 3; // skip that cycle
        }
    } else {
        if (skip_count == 0) {
            cycle_count = 3;
        }
    }

    int cur_pos = 0;
    while (skip_count--) {
        putchar(buffer[cur_pos]);
        cur_pos++;
    }

    while (buffer[cur_pos] != 0) {
        if (cycle_count == 0) {
            putchar(',');
        }
        putchar(buffer[cur_pos]);
        cur_pos++;
        cycle_count = (cycle_count + 1) % 3;
    }

    return 0;
}


