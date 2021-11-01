from distutils.core import setup, Extension

module1 = Extension("gcd",
                    include_dirs=[input('Path where .h are located: ')],
                    libraries=['libgmp'],
                    library_dirs=[input('Path where gmp library is located: ')],
                    sources=['gcd_python.c'])

setup(
    name="gcd",
    version="1.0",
    description="This is a gcd package",
    ext_modules=[module1],
)
