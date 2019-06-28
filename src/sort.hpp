//
// Created by tianpei on 19-6-28.
//

#ifndef ALGORITHMS_SORT_HPP
#define ALGORITHMS_SORT_HPP

#include <vector>
#include <cstring>

class Sort{
public:
    template <typename T>
    static void insertionSort(std::vector<T>& inputArray){
        if(inputArray.size()<2)
            return;
        for(int i=1;i<inputArray.size();++i){
            int j;
            T temp=inputArray[i];
            for(j=i-1;j>=0;--j){
                if(inputArray[j]>inputArray[i])
                    continue;
                else{
                    memcpy(inputArray.data()+j+2,inputArray.data()+j+1, sizeof(T)*(i-j-1));
                    inputArray[j+1]=temp;
                    break;
                }
            }
            if(j==-1){
                memcpy(inputArray.data()+1,inputArray.data(), sizeof(T)*i);
                inputArray[j+1]=temp;
            }

        }
    }

    template <typename T>
    static void binarySort(std::vector<T>& inputArray){
        if(inputArray.size()<2)
            return;
        for(int i=1;i<inputArray.size();++i){
            T temp=inputArray[i];
            int left=0;
            int right=i;
            while(right-left>1){
                int j=(left+right)/2;
                if(inputArray[j]==inputArray[i]){
                    left=j;
                    break;
                }
                if(inputArray[j]>inputArray[i]){
                    right=j;
                    continue;
                }
                else{
                    left=j;
                    continue;
                }
            }
            if(left==0&&inputArray[left]>inputArray[i])
                left=-1;
            memcpy(inputArray.data()+left+2,inputArray.data()+left+1, sizeof(T)*(i-left-1));
            inputArray[left+1]=temp;
        }
    }

    template <typename T>
    static void quickSort(std::vector<T>& inputArray){

    }

    template <typename T>
    static void mergeSort(std::vector<T>& inputArray){

    }

    template <typename T>
    static void bubbleSort(std::vector<T>& inputArray){
        if(inputArray.size()<2)
            return;
        int k=1;
        while(k<inputArray.size()){
            for(int j=0;j<inputArray.size()-k;++j){
                if(inputArray[j+1]<inputArray[j]){
                    T temp=inputArray[j+1];
                    inputArray[j+1]=inputArray[j];
                    inputArray[j]=temp;
                }
            }
            k++;
        }
    }

    template <typename T>
    static void shellSort(std::vector<T>& inputArray){

    }

    template <typename T>
    static void heapSort(std::vector<T>& inputArray){

    }

    template <typename T>
    static void selectionSort(std::vector<T>& inputArray){

    }
};

#endif //ALGORITHMS_SORT_HPP
