#include <Python.h>
#include "gcd.h"

static PyObject* gcd_python(PyObject *self, PyObject *args){
  if (PyTuple_Size(args) != 2){
    PyErr_SetString(self, "not enough args");
  }
  const char *num1, *num2;
  char* res;
  PyArg_ParseTuple(args, "BB", &num1, &num2);
  mpz_t a, b, c;
  mpz_init_set_str(a, num1, 10);
  mpz_init_set_str(b, num2, 10);
  mpz_init(c);
  gcd(a, b, c);
  res = mpz_get_str(NULL, 10, c);
  PyObject* result = PyLong_FromString(res, NULL, 10);
  free(res);
  free(num1);
  free(num2);
  mpz_clear(a);
  mpz_clear(b);
  mpz_clear(c);
  return result;
}

static PyObject *GCDError;

static PyMethodDef methods[] = {
  {"gcd", gcd_python, METH_VARARGS, "computes gcd"},
  {NULL, NULL, 0, NULL}
};

static struct PyModuleDef module = {
  PyModuleDef_HEAD_INIT, "gcd", "Fast gcd computation", -1, methods
};

PyMODINIT_FUNC PyInit_gcd(void)
{
  PyObject *m;
  m = PyModule_Create(&module);
  if (m == NULL)
    return NULL;
  GCDError = PyErr_NewException("gcd.error", NULL, NULL);
  Py_XINCREF(GCDError);
  if (PyModule_AddObject(m, "error", GCDError) < 0) {
      Py_XDECREF(GCDError);
      Py_CLEAR(GCDError);
      Py_DECREF(m);
      return NULL;
  }
  return m;
}
