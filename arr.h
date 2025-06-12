#ifndef ARR_H
#define ARR_H
#include<iostream>
using namespace std;
template <typename T>
class DA {
private:
    T* arr;
    int len;
    int cap;
    void regrow() {
        T* temp = new T[this->cap * this->cap + 1];
        for (int i = 0;i < this->len;i++) {
            temp[i] = arr[i];
        }
        delete[] this->arr;
        this->cap = this->cap * this->cap + 1;
        this->arr = temp;
    };

public:
    DA() {
        len = 0;
        cap = 1;
        arr = nullptr;
    }


    DA(const int count, const T value) {
        this->len = count;
        this->cap = count + 1;
        this->arr = new T[this->cap];
        for (int i = 0;i < count;i++) {
            this->arr[i] = value;
        }
    }

    DA(const T& ptr) {
        int i = 0;
        this->len = 0;
        this->cap = 1;
        this->arr = new T[this->cap + 1];
        /* while (ptr[i] != '\0') {*/
        if (this->len == this->cap) {
            this->regrow();
            this->arr[this->len] = ptr;
            this->len++;
        }
        else {
            this->arr[this->len] = ptr;
            this->len++;
        }
        /* i++;*/
     //}
    }

    //copy
    DA(const DA& others) {

        this->len = others.len;
        this->cap = others.cap;
        this->arr = new T[this->cap];
        for (int i = 0;i < this->len;i++) {
            this->arr[i] = others.arr[i];
        }
    }

    DA& operator=(const DA& other)
    {

        delete[] this->arr;
        this->len = other.len;
        this->cap = other.cap;
        this->arr = new T[this->cap];
        for (int i = 0;i < this->len;i++) {
            this->arr[i] = other.arr[i];
        }
        return *this;
    }


    // []
    T& operator[](const int i) {
        if (i < this->len || i >= 0) {
            return this->arr[i];
        }

    };
    //const []
    const T& operator[](int i) const {
        if (i < this->len && i >= 0) {
            return this->arr[i];
        }
    }
    // ==
    bool operator==(const DA& other)const {
        for (int i = 0;i < this->len;i++) {
            if (this->arr[i] == other.arr[i]) {
                continue;
            }
            else {
                return false;
            }
        }
        return true;
    }
    // !=
    bool operator!=(const DA& other)const {
        for (int i = 0;i < this->len;i++) {
            if (this->arr[i] != other.arr[i]) {
                continue;
            }
            else {
                return false;
            }
        }
        return true;
    }
    //+
    DA operator+(const DA& other)const {
        DA result;
        result.len = other.len + this->len;
        result.cap = other.cap + this->cap;
        result.arr = new T[result.cap + 1];
        int count = 0;
        for (int i = 0;i < this->len;i++) {
            result.arr[i] = this->arr[i];
            count++;
        }
        for (int i = 0;i < other.len;i++) {
            result.arr[count] = other.arr[i];
            count++;
        }
        result.len = count;
        return result;
    }
    // +=
    DA& operator+=(const DA& other) {
        *this = *this + other;
        return *this;
    }
    void add(const T& i) {
        if (this->len >= this->cap) {
            this->regrow();
            this->arr[this->len] = i;
            this->len++;
        }
        else {
            this->arr[this->len] = i;
            this->len++;
        }
    }
    void pop() { this->len--; }
    void insert_at(const T& i, const T& ch) {
        for (int j = 0;j < this->len;j++) {
            if (i == j) {
                this->len++;
                if (this->len >= this->cap) {
                    *this = regrow();
                    DA temp;
                    temp.len = this->len;
                    temp.cap = this->cap;
                    temp.arr = new T[temp.cap + 1];
                    for (int j = 0, k = 0;j < this->len;) {
                        if (j == i && k == j) {
                            temp.arr[k] = ch;
                            k++;

                        }
                        else {
                            temp.arr[k] = this->arr[j];
                            k++;
                            j++;
                        }
                    }
                    *this = temp;
                }
                else {
                    DA temp;
                    temp.len = this->len;
                    temp.cap = this->cap;
                    temp.arr = new T[temp.cap + 1];
                    for (int j = 0, k = 0;j < this->len;) {
                        if (j == i && k == j) {
                            temp.arr[k] = ch;
                            k++;

                        }
                        else {
                            temp.arr[k] = this->arr[j];
                            k++;
                            j++;
                        }
                    }
                    *this = temp;
                }

                break;
            }

        }
    }
    void remove_at(const int& i) {
        if (i < 0 || i > this->len) {
            return;
        }
        for (int j = 0;j < this->len;j++) {
            if (j == i) {
                for (int k = j;k < this->len;k++) {
                    T temp = this->arr[k];
                    this->arr[k] = this->arr[k + 1];
                    this->arr[k + 1] = temp;
                }
                this->len--;
                break;
            }
        }
    }
    void clear() {
        this->len = 0;
    }
    void swap_array(DA& others) {
        DA temp(*this);
        *this = others;
        others = temp;
    }

    void shrink_to_fit() {

        if (this->len != this->cap) {
            if (this->cap < this->len) {
                while (this->cap < this->len) {
                    this->cap++;
                }
            }
            else {
                while (this->len < this->cap) {
                    this->cap--;
                }
            }
        }
        else {
            return;
        }
    }
    /*  void reverse() {
          T* temp = new T[this->len];
          for (int i = this->len - 1, j = 0;i >= 0;i--, j++) {
              temp[j] = this->arr[i];
          }
          for (int i = 0;i < this->len;i++) {
              this->arr[i] = temp[i];
          }
          delete temp[];
      }*/
      //reserve
    void reserve(int new_capacity) {
        while (this->cap <= new_capacity) {
            *this = regrow();
        }
    }
    //Acessors=========
    bool isempty() const {
        if (this->len == 0) {
            return true;
        }
        else {
            return false;
        }
    }


    int size()const {
        return this->len;
    }


    // whts is ion that index 
    T& at(int idx) {
        return this->arr[idx];
    }
    const   T& at(int idx) const {
        return this->arr[idx];
    }
    T& front() {
        return this->arr[0];
    }
    const T& front() const {
        return this->arr[0];
    }
    T& back() {
        return this->arr[this->len - 1];
    }
    const T& back() const {
        return this->arr[this->len - 1];
    }
    void display() const {
        for (int i = 0;i < this->len;i++) {
            cout << arr[i] << " ";
        }
    }
    ~DA() {
        delete[] arr;
    }

    /* template <typename U>
     friend ostream& operator<<(ostream& os, const DA& other) {
         for (int i = 0;i < other.len;i++) {
             cout << other.arr[i] << " ";
         }
         return os;
     }*/
};


#endif // 