## Original example from @mrocklin
This example uses C code within Python using the ctypes library. 

This is the simplest example of which I am aware.

Files to study: test.cpp, test.py

    gcc -shared -fPIC test.c -o test.so
    python test.py



## Example with returning a array of objects which contains another array of objects

This example shows how return a Object array with fixed length, as a dynamic Point array without previous knowledgement of their length.
   
Files to study: object.cpp, point.cpp, object.py

    g++ -shared -fPIC *.cpp -o object.so
    python object.py
