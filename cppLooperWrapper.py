from ctypes import cdll
import ctypes
lib = cdll.LoadLibrary('./pyBind.so')

lib.CppLooper_new.argtypes = []
lib.CppLooper_new.restype = ctypes.c_void_p

lib.CppLooper_loopIt.argtypes = [ctypes.c_void_p]
lib.CppLooper_loopIt.restype = None

lib.CppLooper_getLCount.argtypes = [ctypes.c_void_p]
lib.CppLooper_getLCount.restype = ctypes.c_int

lib.CppLooper_setLCount.argtypes = [ctypes.c_void_p, ctypes.c_int]
lib.CppLooper_getLCount.restype = None

lib.CppLooper_getLCpow.argtypes = [ctypes.c_void_p]
lib.CppLooper_getLCpow.restype = ctypes.c_bool

lib.CppLooper_setLCpow.argtypes = [ctypes.c_void_p, ctypes.c_bool]
lib.CppLooper_setLCpow.restype = None

class CppLooper:

    __slots__ = ["obj"]

    def __init__(self, loopCount=0, lcWithPow=False):
        self.obj = lib.CppLooper_new()
        # self.loopCount = loopCount
        # self.lcWithPow = lcWithPow

    @property
    def loopCount(self):
        return lib.CppLooper_getLCount(self.obj)

    @loopCount.setter
    def loopCount(self, lc):
        lib.CppLooper_setLCount(self.obj, lc)

    @property
    def lcWithPow(self):
        return lib.CppLooper_getLCpow(self.obj)
    
    @lcWithPow.setter
    def lcWithPow(self, lp):
        lib.CppLooper_setLCpow(self.obj, ctypes.c_bool(lp))

    def loopIt(self):
        return lib.CppLooper_loopIt(self.obj)

    # def __del__(self):
    #     lib.CppLooper_del(self.obj)
