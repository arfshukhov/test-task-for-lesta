
#include <cmath>


//реализация цикличного буффера
template <typename Type, const int Size>
class RingBuffer{
public:
    Type *buffer;
    RingBuffer<Type, Size>(){
        buffer = new Type[Size];

    }
    ~RingBuffer(){
        delete buffer;
    }
    Type operator[](int index){
        if (index >= Size){
            while (index >= Size){
                index -= Size;
            }
        }
        else if(index < 0){
            while(index <0){
                index += Size;
            }
        }
        auto ret = buffer[index];
        return ret;
    }
};


//реализация проверки на четность
bool isEven(int i){
    if(i % 2 == 0) return true;
    else return false;
}


//реализация быстрой сортировки
void quicksort(int* mas, int size){
    int start, end, mid_element;
    start = 0;
    end = size-1;
    mid_element = mas[size/2];

    while(start <= end){
        while(mas[start] < mid_element) {
            start++;
        }
        while(mas[end] > mid_element){
            end--;
        }
        if(start<=end){
            std::swap(mas[start], mas[end]);
            start++;
            end--;
        }
        if (end>0){
            quicksort(mas, end+1);
        }
        if (start <size){
            quicksort(&mas[start], size-start);
        }
    }
}
