import gc
from time import sleep
from psutil import Process
from tuple_fun import pytuple, stltuple

if __name__ == "__main__":
    print("memory usage:", Process().memory_full_info())

    print("pytuple()")
    for i in range(10000000): pytuple()
    gc.collect()
    print("memory usage:", Process().memory_full_info())

    print("stltuple()")
    for i in range(10000000): stltuple()
    gc.collect()
    print("memory usage:", Process().memory_full_info())

    print("sleeping...")
    sleep(5)
