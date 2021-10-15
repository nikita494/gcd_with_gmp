from distutils.core import setup, Extension

module1 = Extension("gcd", sources=["gcd.c"])

setup(
    name="gcd",
    version="1.0",
    description="This is a gcd package",
    ext_modules=[module1],
)
