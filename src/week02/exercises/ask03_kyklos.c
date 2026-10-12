#include <stdio.h>

#define PI 3.14159

int main(void) {
    double aktina = 4.5;
    double embado = PI * aktina * aktina;
    double perimetros = 2 * PI * aktina;

    printf("Aktina: %.2f\n", aktina);
    printf("Embado: %.2f\n", embado);
    printf("Perimetros: %.2f\n", perimetros);
    return 0;
}
