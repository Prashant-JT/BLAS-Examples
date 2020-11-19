import time
import numpy as np

def function1():
    for i in range(2, 501):
        A = np.random.rand(i,i)
        B = np.random.rand(i,i)

        start = time.time()
        for j in range(0, 100):
            np.dot(A,B)
        fin= time.time()
        total_time = (fin - start) / 100
        
        print(total_time)


if __name__ == "__main__":
        function1()
        #A = np.random.rand(2,2)
        #A.astype(double)
        #print(A.dtype)
