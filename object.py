import ctypes
import struct

class Point(ctypes.Structure):
    _fields_ = [
        ('x', ctypes.c_int),
        ('y', ctypes.c_int),
        ('z', ctypes.c_int)
    ]

class Object(ctypes.Structure):
    _fields_ = [
        ('id', ctypes.c_int),
        ('pointsLength', ctypes.c_int),
        ('points', ctypes.POINTER(Point))
    ]

   
def setup_lib(lib_path):
    lib = ctypes.cdll.LoadLibrary(lib_path)

    lib.Object_test.restype = ctypes.POINTER(Object) 
    lib.Object_testArray.restype = ctypes.POINTER(Object * 3)

    lib.Object_cleanup_object.argtypes = [ctypes.POINTER(Object)]
    lib.Object_cleanup_ArrayObject.argtypes = [ctypes.POINTER(Object)]    

    return lib

lib = setup_lib('./object.so')
objTeste = lib.Object_test()
print('id ',objTeste.contents.id)
print('point x ', objTeste.contents.points.contents.x)
print('point y ', objTeste.contents.points.contents.y)
print('point z ', objTeste.contents.points.contents.z)
lib.Object_cleanup_object(objTeste)

array = lib.Object_testArray()
print('Printing array')
for obj in array.contents:
    print(obj.pointsLength)
    i = 0
    for i in range(obj.pointsLength):
        print(i, obj.points[i].x, obj.points[i].y, obj.points[i].z)
    
lib.Object_cleanup_ArrayObject(array.contents)