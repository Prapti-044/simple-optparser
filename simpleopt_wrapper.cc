#include <Python.h>

#if PY_MAJOR_VERSION < 3
#error "Requires Python 3"
#include "stopcompilation"
#endif

#include "simpleopt.h"


#include <iostream>

static PyObject *method_decode(PyObject *self, PyObject *args) {
    char *binaryFilePath = NULL;

    /* Parse arguments */
    if(!PyArg_ParseTuple(args, "ss", &binaryFilePath)) {
        return NULL;
    }

    if(!decode(binaryFilePath))
        // TODO: Throw python exception here
        return PyLong_FromLong(-1);

    return PyLong_FromLong(0);
}

static PyObject *method_printParseString(PyObject *self, PyObject *args) {
    std::string ret = printParseString();
    return PyUnicode_FromString(ret.c_str());
}

static PyObject *method_hello(PyObject *self, PyObject *args) {
    int ret = hello("klsdjfkls");
    return PyUnicode_FromString("lskdjf");
}


static PyMethodDef SimpleOptMethods[] = {
    {"decode", method_decode, METH_VARARGS, "Python interface for decode C function"},
    {"printparsestring", method_printParseString, METH_VARARGS, "return the json string"},
    {"hello", method_hello, METH_VARARGS, "hellosadikjfo"},
    {NULL, NULL, 0, NULL}
};


static struct PyModuleDef simpleoptmodule = {
    PyModuleDef_HEAD_INIT,
    "simpleoptparser",
    "Python interface for the simpleopt C file",
    -1,
    SimpleOptMethods
};

PyMODINIT_FUNC PyInit_simpleoptparser(void) {
    return PyModule_Create(&simpleoptmodule);
}

