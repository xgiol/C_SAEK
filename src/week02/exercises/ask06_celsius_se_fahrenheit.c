#include <stdio.h>

int main(void) {
    double celsius = 25.0;
    double fahrenheit = celsius * 9.0 / 5.0 + 32.0;
    printf("%.1f C = %.1f F\n", celsius, fahrenheit);
    return 0;
}
