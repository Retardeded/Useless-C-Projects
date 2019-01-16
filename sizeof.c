//author: Piotr Kurek
#include <stdio.h>
#include <float.h>
#include <limits.h>
#include <stdint.h>

int main()
{

printf("sizeof(int) = %zu in [%d, %d]\n", sizeof(int), INT_MIN, INT_MAX);
printf("sizeof(unsigned) = %zu in [%d, %u]\n", sizeof(unsigned int), 0, UINT_MAX);
printf("sizeof(long) = %zu in [%ld, %ld]\n", sizeof(long), LONG_MIN, LONG_MAX);
printf("sizeof(unsigned long) = %zu in [%d, %lu]\n", sizeof(unsigned long), 0, ULONG_MAX);
printf("sizeof(short) = %zu in [%d, %d]\n", sizeof(short), SHRT_MIN, SHRT_MAX);
printf("sizeof(unsigned short) = %zu in [%d, %d]\n", sizeof(unsigned short), 0, USHRT_MAX);
printf("sizeof(char) = %zu in [%d, %d]\n", sizeof(char), CHAR_MIN, CHAR_MAX);
printf("sizeof(unsigned char) = %zu in [%d, %d]\n", sizeof(unsigned char), 0, UCHAR_MAX);
printf("sizeof(signed char) = %zu in [%d, %d]\n", sizeof(signed char), SCHAR_MIN, SCHAR_MAX);
printf("sizeof(long long) = %zu in [%lld, %lld]\n", sizeof(long long), LLONG_MIN, LLONG_MAX);
printf("sizeof(long long unsigned) = %zu in [%d, %llu]\n", sizeof(unsigned long long), 0, ULLONG_MAX);

printf("sizeof(float) = %zu in [%e, %e]\n", sizeof(float), (double)FLT_MIN, (double)FLT_MAX);
printf("sizeof(double) = %zu in [%le, %le]\n", sizeof(double), DBL_MIN, DBL_MAX);
printf("sizeof(long double) = %zu in [%lle, %lle]\n", sizeof(long double), LDBL_MIN, LDBL_MAX);

printf("sizeof(int_fast16_t) = %zu in [%ld, %ld]\n", sizeof(int_fast16_t), INT_FAST16_MIN, INT_FAST16_MAX);
printf("sizeof(int_least16_t) = %zu in [%d, %d]\n", sizeof(int_least16_t), INT_LEAST16_MIN, INT_LEAST16_MAX);

return 0;
}
