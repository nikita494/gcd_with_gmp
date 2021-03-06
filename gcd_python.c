#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "gcd.h"

static PyObject* gcd_python(PyObject *self, PyObject *args){
  PyObject* py1;
  PyObject* py2;
  if ((PyTuple_Size(args) != 2) & !PyArg_ParseTuple(args, "OO", &py1, &py2)){
    PyErr_SetString(PyExc_TypeError, "Not enough args!");
    return NULL;
  }
  else if (!PyLong_Check(py1) | !PyLong_Check(py2)){
    PyErr_SetString(PyExc_TypeError, "None integer args!");
    return NULL;
  }
  const char *num1, *num2, *res;
  num1 = PyUnicode_AsUTF8(PyUnicode_FromFormat("%A", py1));
  num2 = PyUnicode_AsUTF8(PyUnicode_FromFormat("%A", py2));
  mpz_t a, b, c;
  mpz_init_set_str(a, num1, 10);
  mpz_init_set_str(b, num2, 10);
  mpz_init(c);
  mpz_gcd(c, a, b);
  res = mpz_get_str(NULL, 10, c);
  PyObject* result = PyLong_FromString(res, NULL, 10);
  mpz_clear(a);
  mpz_clear(b);
  mpz_clear(c);
  return result;
}

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
  return m;
}
