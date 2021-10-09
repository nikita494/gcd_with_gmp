#include <stdio.h>
#include <gmp.h>
#define GMP_INT mpz_t

void gcd(const GMP_INT num1, const GMP_INT num2, GMP_INT res){
  GMP_INT c, a, b;
  mpz_init_set(a, num1);
  mpz_init_set(b, num2);
  mpz_init(c);
  if (mpz_cmp(a, b) < 0){
    mpz_swap(a, b);
  }
  mpz_mod(c, a, b);
  while (mpz_cmp_ui(c, 0L) != 0){
    mpz_set(a, b);
    mpz_set(b, c);
    mpz_mod(c, a, b);
  }
  mpz_set(res, b);
  mpz_clear(c);
  mpz_clear(a);
  mpz_clear(b);
  return;
}

int main(){
  GMP_INT x, y, res;
  char x_str[1000], y_str[1000], res_str[1000];
  scanf("%s", x_str);
  scanf("%s", y_str);
  mpz_init_set_str(x, x_str, 10);
  mpz_init_set_str(y, y_str, 10);
  mpz_init(res);
  gcd(x, y, res);
  mpz_get_str(res_str, 10, res);
  printf("%s\n", res_str);
  mpz_clear(x);
  mpz_clear(y);
  mpz_clear(res);
}
