#include <stdio.h>
#include <gmp.h>

void gcd(const mpz_t num1, const mpz_t num2, mpz_t res){
  mpz_t c, a, b;
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
