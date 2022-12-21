#include <iostream>

using namespace std;

template <typename T> class Array
{
    private:
        T* ptr;
        int size;

    public:
    Array(T* ptr , int size);
    void print();


};

// template function

template <typename T> Array<T>::Array(T* str, int size)
{
    ptr = new T[size];
    for (int i=0; i < size; i++)
    {
        ptr[i] = str[i];
        std::cout << ptr[i] << "\n";
    }
}
template <typename T> void Array<T>::print()
{
    for(int i = 0; i< size ; i++)
    {

        std::cout<<"Here " <<ptr[i] << "\n";
    }
}
int main()
{
    int arr[6]= {1,2,3,4,5,6};
    Array<int> arr1(arr,6);
    arr1.print();
    return 0; 
}