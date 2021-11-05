from distutils.core import setup, Extension

module1 = Extension("gcd",
                    include_dirs=['D:\c_projects\gmp_lib\include'],
                    libraries=['libgmp'],
                    library_dirs=['D:\c_projects\gmp_lib\lib'],
                    sources=['gcd_python.c'])

setup(
    name="gcd",
    version="1.0",
    description="This is a gcd package",
    ext_modules=[module1],
)
