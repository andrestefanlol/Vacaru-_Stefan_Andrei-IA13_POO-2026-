#pragma once
template <typename K, typename V>
struct MapElement {
    K key;
    V value;
    int index;
};
template <typename K, typename V>
class Map {
private:
    MapElement<K, V>* elements;
    int capacity;
    int count;
    void resize() {
        capacity += 1;
        MapElement<K, V>* newElements = new MapElement<K, V>[capacity];
        for (int i = 0; i < count; ++i) {
            newElements[i] = elements[i];
        }
        delete[] elements;
        elements = newElements;
    }
public:
    Map() {
        capacity = 10;
        count = 0;
        elements = new MapElement<K, V>[capacity];
    }
    ~Map() {
        delete[] elements;
    }
    Map(const Map& other) {
        capacity = other.capacity;
        count = other.count;
        elements = new MapElement<K, V>[capacity];
        for (int i = 0; i < count; ++i) {
            elements[i] = other.elements[i];
        }
    }
    Map& operator=(const Map& other) {
        if (this != &other) {
            delete[] elements;
            capacity = other.capacity;
            count = other.count;
            elements = new MapElement<K, V>[capacity];
            for (int i = 0; i < count; ++i) {
                elements[i] = other.elements[i];
            }
        }
        return *this;
    }
    V& operator[](const K& key) {
        for (int i = 0; i < count; ++i) {
            if (elements[i].key == key) {
                return elements[i].value;
            }
        }
        if (count == capacity) {
            resize();
        }
        elements[count].key = key;
        elements[count].index = count;
        return elements[count++].value;
    }
    void Set(const K& key, const V& value) {
        (*this)[key] = value;
    }
    bool Get(const K& key, V& value) {
        for (int i = 0; i < count; ++i) {
            if (elements[i].key == key) {
                value = elements[i].value;
                return true;
            }
        }
        return false;
    }
    int Count() const {
        return count;
    }
    void Clear() {
        count = 0;
    }
    bool Delete(const K& key) {
        for (int i = 0; i < count; ++i) {
            if (elements[i].key == key) {
                for (int j = i; j < count - 1; ++j) {
                    elements[j] = elements[j + 1];
                    elements[j].index = j;
                }
                count--;
                return true;
            }
        }
        return false;
    }
    bool Includes(const Map<K, V>& map) const {
        for (int i = 0; i < map.Count(); ++i) {
            bool found = false;
            for (int j = 0; j < count; ++j) {
                if (elements[j].key == map.elements[i].key) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                return false;
            }
        }
        return true;
    }
    MapElement<K, V>* begin() const { return elements; }
    MapElement<K, V>* end() const { return elements + count; }
};