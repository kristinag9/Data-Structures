#include <iostream>
#include <vector>
#include <iostream>

class IntVector 
{
public:
    int *data;
    size_t size;

    void init() {
        size = 0;
        data = nullptr;
    }

    void push_back(int x) {
        int* biggerBuffer = new int[size + 1];
        for (size_t i = 0; i < size; i++) {
            biggerBuffer[i] = data[i];
        }
        biggerBuffer[size] = x;
        size++;

        delete data;

        data = biggerBuffer;
    }

    void push(int x) {
        int* buffer = new int[size + 1];
        for (size_t i = 0; i < size; i++) {
            buffer[i + 1] = data[i];
        }

        buffer[0] = x;
        ++size;

        delete data;
        data = buffer;
    }

    IntVector operator+(IntVector other) {
        IntVector result;
        result.init();

        result.data = new int[this->size + other.size];

        for (size_t i = 0; i < this->size; i++) {
            result.data[i] = this->data[i];
        }

        for (size_t i = 0; i < other.size; i++) {
            result.data[this->size + i] = other.data[i];
        }

        result.size = this->size + other.size;
        return result;
   }

};

std::ostream& operator<<(std::ostream& out, IntVector v) 
{
    for (size_t i = 0; i < v.size; i++) {
        std::cout << v.data[i] << " ";
    }

    return out;
}

int main()
{
    IntVector v;
    v.init();

    v.push_back(0);
    v.push_back(1);
    v.push_back(2);

    v.push(10);
    v.push(11);
    v.push(12);

    std::cout << v << std::endl;


    IntVector v2;
    v2.push_back(1);
    v2.push_back(2);
    v2.push_back(3);

    std::cout << "Result = " << v + v2 << std::endl;

    return 0;
}
