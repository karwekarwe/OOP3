#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <iterator>
#include <limits>

template <typename T>
class Vector {
    public:
    using size_type = size_t;
    using value_type = T;
    using reference  = T&;
    using const_reference = const T&;
    using iterator = T*;
    using const_iterator = const T*;  
    using pointer = T*;                          
    using const_pointer = const T*;  
    using reverse_iterator = std::reverse_iterator<iterator>;       
    using const_reverse_iterator = std::reverse_iterator<const_iterator>; 


    

    //default konstruktorius
    Vector() : _size(0), _capacity(0), _data(nullptr) {}

    //fill konstruktorius
    Vector(size_type count, const value_type& value = value_type()) 
    : _size(count), _capacity(count), _data(new value_type[count]) {
    std::fill(_data, _data + _size, value);
    }

    //copy konstruktorius
    Vector(const Vector& other) 
    : _size(other._size), _capacity(other._capacity), _data(new value_type[other._capacity]) {
    std::copy(other._data, other._data + _size, _data);
    }

    //move konstruktorius
    Vector(Vector&& other) noexcept 
        : _size(other._size), _capacity(other._capacity), _data(other._data) {
        other._size = 0;
        other._capacity = 0;
        other._data = nullptr;
    }

    //copy assignment operatorius
    Vector& operator=(const Vector& other) {
        if (this != &other) {
            value_type* new_data = new value_type[other._capacity];
            std::copy(other._data, other._data + other._size, new_data);
            delete[] _data;
            _data = new_data;
            _size = other._size;
            _capacity = other._capacity;
        }
        return *this;
    }

    //move assignment operatorius
    Vector& operator=(Vector&& other) noexcept {
        if (this != &other) {
            delete[] _data;
            _data = other._data;
            _size = other._size;
            _capacity = other._capacity;
            other._data = nullptr;
            other._size = 0;
            other._capacity = 0;
        }
        return *this;
    }
    //member functions:

    //destruktorius
        ~Vector() { delete[] _data;}

    // Element access - grazina elemento reference nurodytoj lokacijoj
    reference operator[](size_type pos) {
        return _data[pos];
    }

    //const element access
    const_reference operator[](size_type pos) const {
        return _data[pos];
    }
    //su bounds check
    reference at(size_type pos) {
        if (pos >= _size) {
            throw std::out_of_range("Vector::at: index out of range");
        }
        return _data[pos];
    }

    const_reference at(size_type pos) const {
        if (pos >= _size) {
            throw std::out_of_range("Vector::at: index out of range");
        }
        return _data[pos];
    }

     // pirmo elemento reference
    reference front() {
        return _data[0];
    }

     // const pirmo elemento reference
    const_reference front() const {
        return _data[0];
    }

    // paskutinio elemento reference
    reference back() {
        return _data[_size - 1];
    }

    // const paskutinio elemento reference
    const_reference back() const {
        return _data[_size - 1];
    }

    // pointeris i pirma vektoriaus internal array elementa
    pointer data() noexcept {
        return _data;
    }

    // const pointeris i pirma vektoriaus internal array elementa
    const_pointer data() const noexcept {
        return _data;
    }

    //capacity
    // dydis - grazina elementu sk
    size_type size() const noexcept {
        return _size;
    }

    //talpa - grazina kiek elementu telpa dabar
    size_type capacity() const noexcept {
        return _capacity;
    }

    //ar empty
    bool empty() const noexcept {
        return _size == 0;
    }

    //max sk elementu
    size_type max_size() const noexcept {
    return std::numeric_limits<size_type>::max();
    }

    //rezervuoja didesne talpa
    void reserve(size_type new_cap) {
        if (new_cap > _capacity) {
            value_type* new_data = new value_type[new_cap];
            std::copy(_data, _data + _size, new_data);
            delete[] _data;
            _data = new_data;
            _capacity = new_cap;
        }
    }

    //freeina nenaudojama atminti
     void shrink_to_fit() {
        if (_capacity > _size) {
            value_type* new_data = new value_type[_size];
            std::copy(_data, _data + _size, new_data);
            delete[] _data;
            _data = new_data;
            _capacity = _size;
        }
    }

    //padidina talpa
    void resize(size_type count, value_type value = value_type()) {
        if (count > _capacity) {
            reserve(count);
        }
        if (count > _size) {
            std::fill(_data + _size, _data + count, value);
        }
        _size = count;
    }

    //modifiers:

    //push
    void push_back(const value_type& value) {
        if (_size == _capacity) {
            reserve(_capacity == 0 ? 1 : 2 * _capacity);
        }
        _data[_size++] = value;
    }

    //pop
    void pop_back() {
        if (_size > 0) {
            --_size;
        }
    }

    //clear
     void clear() noexcept {
        _size = 0;
    }

    //insertina i norima vieta
     iterator insert(const_iterator pos, const value_type& value) {
        size_type index = pos - begin();
        if (_size == _capacity) {
            reserve(_capacity == 0 ? 1 : 2 * _capacity);
        }
        std::copy_backward(begin() + index, end(), end() + 1);
        _data[index] = value;
        ++_size;
        return begin() + index;
    }

    //erasina specifinej vietoj
      iterator erase(const_iterator pos) {
        size_type index = pos - begin();
        std::copy(begin() + index + 1, end(), begin() + index);
        --_size;
        return begin() + index;
    }

    //swapina su kitu vectorium
     void swap(Vector& other) noexcept {
        std::swap(_data, other._data);
        std::swap(_size, other._size);
        std::swap(_capacity, other._capacity);
    }

     // Iteratoriai:

     //grazina pradzios it
    iterator begin() noexcept {
        return _data;
    }

    //grazina const pradzios it
    const_iterator begin() const noexcept {
        return _data;
    }

    //grazina pabaigos it
    iterator end() noexcept {
        return _data + _size;
    }

    //grazina pabaigos const it
    const_iterator end() const noexcept {
        return _data + _size;
    }

    // reverse iteratorius pradzios
    reverse_iterator rbegin() noexcept {
        return reverse_iterator(end());
    }
    // const reverse iteratorius pradzios
     const_reverse_iterator rbegin() const noexcept {
        return const_reverse_iterator(end());
    }

    // reverse iteratorius pabaigos
     reverse_iterator rend() noexcept {
        return reverse_iterator(begin());
    }

    // const reverse iteratorius pabaigos
    const_reverse_iterator rend() const noexcept {
        return const_reverse_iterator(begin());
    }




    private:
    size_type _size;       
    size_type _capacity;   
    value_type* _data;     

};

// Non-member 

// tikrina ar lygus
template <typename T>
bool operator==(const Vector<T>& lhs, const Vector<T>& rhs) {
    return lhs.size() == rhs.size() && std::equal(lhs.begin(), lhs.end(), rhs.begin());
}

//tikrina ar nelygus
template <typename T>
bool operator!=(const Vector<T>& lhs, const Vector<T>& rhs) {
    return !(lhs == rhs);
}

// std::swap sitam vektorius
template <typename T>
void swap(Vector<T>& lhs, Vector<T>& rhs) noexcept {
    lhs.swap(rhs);
}

// erase
template <typename T, typename UnaryPredicate>
typename Vector<T>::iterator erase_if(Vector<T>& vec, UnaryPredicate p) {
    auto it = std::remove_if(vec.begin(), vec.end(), p);
    auto res = vec.end();
    if (it != vec.end()) {
        res = vec.erase(it, vec.end());
    }
    return res;
}

// output
template <typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& vec) {
    os << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        os << vec[i];
        if (i != vec.size() - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}