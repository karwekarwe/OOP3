template <typename T>
class Vector {
    T* p; // pointeris
    int capacity; // storage
    int current; //elementu sk

    public:
        Vector()
        {
            p = new T[1];
            capacity = 1;
            current = 0;
        }

    ~Vector() { delete[] p; } //destructorius

    void push(T data) { //push
        if(current == capacity){
            T temp = new T[2 * capacity];

             for (int i = 0; i < capacity; i++) {
                temp[i] = arr[i];
            }

             for (int i = 0; i < capacity; i++) {
                temp[i] = arr[i];
            }
        }
            arr[current] = data;
            current++;
    }

    void pop (T data) {
        current--;
    }
    int size() { 
        return current; 
    }
    int getcapacity() { 
        return capacity; 
    }
    void print()
    {
        for (int i = 0; i < current; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << endl;
    }
};