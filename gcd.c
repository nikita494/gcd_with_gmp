#include <Python.h>
#include <stdio.h>
#include <gmp.h>
#include "gcd.h"

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

static PyMethodDef methods[] = {
  {"gcd", gcd_python, METH_VARARGS, "computes gcd"},
  {NULL, NULL, 0, NULL}
};

static struct PyModuleDef module = {
  PyModuleDef_HEAD_INIT, "GCD", "Fast gcd computation", -1, methods
};

static PyObject *
gcd_python(PyObject *self, PyObject *args){
  if (PyTuple_Size(args) != 2){
    PyErr_SetString(self, "not enough args");
  }
  const char *num1, *num2;
  char* res;
  PyArg_ParseTuple(args, "bb", &num1, &num2);
  mpz_t a, b, c;
  mpz_init_set_str(a, num1, 10);
  mpz_init_set_str(b, num2, 10);
  mpz_init(c);
  gcd(a, b, c);
  res = (char*)malloc(mtz_sizeinbase(c, 10)*sizeof(char));
  PyObject* result = PyLong_FromString(res, NULL, 10);
  free(res);
  mpz_clear(a);
  mpz_clear(b);
  mpz_clear(c);
  return result;
}
