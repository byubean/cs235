

void grow(int* array, unsigned int & capacity) {
    int* old = array;
    unsigned int old_cap = capacity;
    capacity *= 2;
    array = new int[capacity];
    for (int i = 0; i < capacity; i++) {
        array[i] = old[i];
    }
    delete[] old;
}