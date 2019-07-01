#include <iostream>
#include <chrono>
#include <algorithm>
#include <thread>
#include <sort.hpp>

using namespace std;

void testSort(){
    cout<<"--------------------------------"<<endl;
    cout<<"Test sorting algorithms..."<<endl;

    //initialize testing arrays
    vector<int> numArray({10,100,1000,10000,100000});

    vector<vector<int>> tests(numArray.size());
    for(int i=0;i<numArray.size();++i){
        tests[i]=vector<int>(numArray[i],0);
        for(int& a:tests[i])
            a=random();
    }

    //execution time for all methods
    vector<vector<double>> time(9,vector<double>(numArray.size()));

    //testing std
    vector<vector<int>> test0=tests;
    for(int i=0;i<numArray.size();++i){
        std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();
        std::sort(test0[i].begin(),test0[i].end());
        std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
        double t_track= std::chrono::duration_cast<std::chrono::duration<double> >(t2 - t1).count();
        time[0][i]=t_track;
    }
    cout<<"\nExecution time"<<endl;
    cout<<"methods ";
    for(int i : numArray)
        cout<<i<<" ";
    cout<<"\nstd ";
    for(int i=0;i<numArray.size();++i)
        cout<<time[0][i]<<" ";

    //testing InsertSort
    thread runInsertSort([&](){
        vector<vector<int>> test=tests;
        for(int i=0;i<numArray.size();++i){
            std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();
            Sort::insertionSort(test[i]);
            std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
            double t_track= std::chrono::duration_cast<std::chrono::duration<double> >(t2 - t1).count();
            time[1][i]=t_track;
            if(test[i]!=test0[i])
                cerr<<"Insertion sort error!!!!"<<endl;
        }
        cout<<"\ninsertion ";
        for(int i=0;i<numArray.size();++i)
            cout<<time[1][i]<<" ";
    });

    //testing binarySort
    thread runBinarySort([&](){
        vector<vector<int>> test=tests;
        for(int i=0;i<numArray.size();++i){
            std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();
            Sort::binarySort(test[i]);
            std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
            double t_track= std::chrono::duration_cast<std::chrono::duration<double> >(t2 - t1).count();
            time[2][i]=t_track;
            if(test[i]!=test0[i])
                cerr<<"Binary sort error!!!!"<<endl;
        }
        cout<<"\nBinary ";
        for(int i=0;i<numArray.size();++i)
            cout<<time[2][i]<<" ";
    });

    //testing bubbleSort
    thread runBubbleSort([&](){
        vector<vector<int>> test=tests;
        for(int i=0;i<numArray.size();++i){
            std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();
            Sort::bubbleSort(test[i]);
            std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
            double t_track= std::chrono::duration_cast<std::chrono::duration<double> >(t2 - t1).count();
            time[3][i]=t_track;
            if(test[i]!=test0[i])
                cerr<<"Bubble sort error!!!!"<<endl;
        }
        cout<<"\nBubble ";
        for(int i=0;i<numArray.size();++i)
            cout<<time[3][i]<<" ";
    });

    //testing selectionSort
    thread runSelectionSort([&](){
        vector<vector<int>> test=tests;
        for(int i=0;i<numArray.size();++i){
            std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();
            Sort::selectionSort(test[i]);
            std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
            double t_track= std::chrono::duration_cast<std::chrono::duration<double> >(t2 - t1).count();
            time[4][i]=t_track;
            if(test[i]!=test0[i])
                cerr<<"Selection sort error!!!!"<<endl;
        }
        cout<<"\nSelection ";
        for(int i=0;i<numArray.size();++i)
            cout<<time[4][i]<<" ";
    });

    //testing quickSort
    thread runQuickSort([&](){
        vector<vector<int>> test=tests;
        for(int i=0;i<numArray.size();++i){
            std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();
            Sort::quickSort(test[i]);
            std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
            double t_track= std::chrono::duration_cast<std::chrono::duration<double> >(t2 - t1).count();
            time[5][i]=t_track;
            if(test[i]!=test0[i])
                cerr<<"Quick sort error!!!!"<<endl;
        }
        cout<<"\nQuick ";
        for(int i=0;i<numArray.size();++i)
            cout<<time[5][i]<<" ";
    });

    //testing heapSort
    thread runHeapSort([&](){
        vector<vector<int>> test=tests;
        for(int i=0;i<numArray.size();++i){
            std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();
            Sort::quickSort(test[i]);
            std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
            double t_track= std::chrono::duration_cast<std::chrono::duration<double> >(t2 - t1).count();
            time[6][i]=t_track;
            if(test[i]!=test0[i])
                cerr<<"Heap sort error!!!!"<<endl;
        }
        cout<<"\nHeap ";
        for(int i=0;i<numArray.size();++i)
            cout<<time[6][i]<<" ";
    });

    //wait all thread exit
    runQuickSort.join();
    runHeapSort.join();
    runBinarySort.join();
    runInsertSort.join();
    runSelectionSort.join();
    runBubbleSort.join();

}

int main() {
    std::cout << "This project is built for training my coding skills and learning normal algorithms." << std::endl;

    testSort();

    return 0;
}