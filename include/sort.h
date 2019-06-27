//
// Created by tianpei on 19-6-27.
//

#ifndef ALGORITHMS_SORT_H
#define ALGORITHMS_SORT_H

#include <vector>

class Sort{
public:
    template <typename T>
    static void binarySort(std::vector<T>& inputArray);

    template <typename T>
    static void quickSort(std::vector<T>& inputArray);

    template <typename T>
    static void mergeSort(std::vector<T>& inputArray);

    template <typename T>
    static void insertionSort(std::vector<T>& inputArray);

    template <typename T>
    static void bubbleSort(std::vector<T>& inputArray);

    template <typename T>
    static void shellSort(std::vector<T>& inputArray);

    template <typename T>
    static void heapSort(std::vector<T>& inputArray);

    template <typename T>
    static void selectionSort(std::vector<T>& inputArray);
};

#endif //ALGORITHMS_SORT_H
