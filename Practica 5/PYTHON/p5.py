import time
import numpy as np
import csv


def function1():
    total_time = []
    for i in range(100, 1001, 20):
        A = np.random.rand(i, i)
        B = np.random.rand(i, i)

        start = time.time()
        for j in range(0, 100):
            np.dot(A, B)
        fin = time.time()
        total_time.append((fin - start) / 100)

    with open("Ejercicion5PYTHON.csv", 'w', newline='') as myfile:
        wr = csv.writer(myfile)
        wr.writerow(total_time)


if __name__ == "__main__":
    function1()
