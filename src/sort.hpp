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
        if(inputArray.size()<2)
            return;
        quickSort3(inputArray,0,inputArray.size()-1);
    }

    template <typename T>
    static void mergeSort(std::vector<T>& inputArray){
        if(inputArray.size()<2)
            return;
        int N=inputArray.size();
        auto temp=inputArray;
        mSort(inputArray,temp,0,N-1);
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
        if(inputArray.size()<2)
            return;

        int N=inputArray.size();
        for(int i=N/2; i>=0;--i){
            percolateDown(inputArray,i,N);
        }

        for(int i=N-1;i>=0;--i){
            swap(inputArray,0,i);
            percolateDown(inputArray,0,i);
        }
    }

    template <typename T>
    static void selectionSort(std::vector<T>& inputArray){
        if(inputArray.size()<2)
            return;

        for(int i=0;i<inputArray.size();++i){
            T min=inputArray[i];
            int min_index=i;
            for(int j=i+1;j<inputArray.size();++j){
                if(inputArray[j]<min){
                    min=inputArray[j];
                    min_index=j;
                }
            }
            if(min_index!=i){
                T temp=inputArray[i];
                inputArray[i]=min;
                inputArray[min_index]=temp;
            }
        }

    }

    //////////////////////private functions//////////////////////////////
    template <typename T>
    static void quickSort3(std::vector<T>& inputArray,int start, int end){
        if(end-start<1)
            return;

        if(end-start>2){
            T mid=medianValue(inputArray,start,end);
            int i=start;
            int j=end-1;
            while(true){
                while(inputArray[++i]<mid){}
                while(inputArray[--j]>mid){}
                if(i<j)
                    swap(inputArray,i,j);
                else
                    break;
            }
            swap(inputArray,i,end-1);

            quickSort3(inputArray,start,i-1);
            quickSort3(inputArray,i+1,end);
        }
        else
            medianValue(inputArray,start,end);
    }

    template <typename T>
    static T medianValue(std::vector<T>& inputArray,int start, int end){
        int median=(start+end)/2;

        if(inputArray[start]>inputArray[end])
            swap(inputArray,start,end);
        if(inputArray[start]>inputArray[median])
            swap(inputArray,start,median);
        if(inputArray[median]>inputArray[end])
            swap(inputArray,median,end);

        swap(inputArray,median,end-1);

        return inputArray[end-1];
    }

    template <typename T>
    static void swap(std::vector<T>& inputArray,int p1, int p2){
        T temp=inputArray[p1];
        inputArray[p1]=inputArray[p2];
        inputArray[p2]=temp;
    }

    template <typename T>
    static void percolateDown(std::vector<T>& inputArray, int i, int N){
        int child;
        T temp;
        for(temp=inputArray[i];2*i+1<N;i=child){
            child=2*i+1;
            if(child!=N-1&&inputArray[child+1]>inputArray[child])
                child++;
            if(temp<inputArray[child])
                inputArray[i]=inputArray[child];
            else
                break;
        }
        inputArray[i]=temp;
    }

    template <typename T>
    static void mSort(std::vector<T>& inputArray,std::vector<T>& tempArray, int start, int end){
        if(start<end){
            int mid=(start+end)/2;
            mSort(inputArray,tempArray,start,mid);
            mSort(inputArray,tempArray,mid+1,end);
            merge(inputArray,tempArray,start,mid+1,end);
        }
    }

    template <typename T>
    static void merge(std::vector<T>& inputArray,std::vector<T>& tempArray,int start, int mid, int end){
        int left=start;
        int right=mid;

        int N=end-start+1;

        for(int i=0;i<N;++i){
            if(inputArray[left]<inputArray[right]){
                tempArray[start+i]=inputArray[left++];
            }
            else{
                tempArray[start+i]=inputArray[right++];
            }
            if(left>=mid){
                memcpy(tempArray.data()+start+i+1,inputArray.data()+right, sizeof(T)*(N-i-1));
                break;
            }
            if(right>end){
                memcpy(tempArray.data()+start+i+1,inputArray.data()+left, sizeof(T)*(N-i-1));
                break;
            }
        }

        for(int i=start;i<=end;++i)
            inputArray[i]=tempArray[i];
    }

};

#endif //ALGORITHMS_SORT_HPP
