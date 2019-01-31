#Original example
This example uses C code within Python using the ctypes library. 

This is the simplest example of which I am aware.

    gcc -shared -fPIC test.c -o test.so
    python test.py



#Example with returning a array of objects which contains another array of objects

This example shows how return a Object array with fixed length, as a dynamic Point array without previous knowledgement

    g++ -shared -fPIC object.cpp -o object.so
    python object.py

About free memory allocations, im not sure if arrays are setting free properly (to be study).