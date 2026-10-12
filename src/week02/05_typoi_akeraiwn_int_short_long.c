#include <stdio.h>
int main() {
// ������ �������� ����� ��������
int normal_integer = 25;
short small_integer = 100;
long big_integer = 1234567890;
long long very_big_integer = 1234567890123456789;
unsigned int only_positive = 4000000000;

// ���� unsigned int ������ �� �������� ���������� ������ ����
// ��� ���� signed int ����� ��������.

printf("int: %d\nshort: %hd\n", normal_integer, small_integer);
printf("int: %d\n", normal_integer);
printf("short: %hd\n", small_integer);
printf("long: %ld\n", big_integer);
printf("long long: %lld\n", very_big_integer);
printf("unsigned int: %u\n", only_positive);

return 0;

}
