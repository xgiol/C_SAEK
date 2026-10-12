#include <stdio.h>

int main(void) {
  int num = 42;
  float pi = 3.14159f;
  char ch = 'A';
  char str[] = "Hello, World!"; // Alfarithmitiko
  printf("Integer: %d\n", num); // Ektyposi enos akeraiou
  printf("Float: %f\n", pi);    // Ektyposi enos float
  printf("Character and its int value: %c %d\n", ch,
         ch); // Ektyposi xaraktira kai tis arithmitikis tou timis
  printf("String: %s\n", str); // Ektyposi enos lektikou
  printf("Octal: %o Hexadecimal: %x\n", num,
         num); // Ektyposi akeraiou se oktadiki kai dekaexadiki morfi
  printf("Width and Padding : %8d\n", num); // Ektyposi me kathorismo platous
  printf("Padding with zeros: %08d\n", num); // Ektyposi me kathorismo platous
  printf("Precision: %.2f\n", pi); // Ektyposi me kathorismo akriveias
  printf("Left-alignment : |%-20s|\n", str); // Aristeri stoixisi
  printf("Right-alignment: |%20s|\n", str);  // Dexia stoixisi
  printf("Print %% character: %%\n"); // Ektyposi tou xaraktira %
  return 0;
}
