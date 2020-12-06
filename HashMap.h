#ifndef HASHMAP_H
#define HASHMAP_H

#include <vector>
#include <fstream>

using namespace std;
template <typename V>
class HashSet {

private:

    static const int DEFAULT_CAPACITY = 4;
    static const int MAXIMUM_CAPACITY = 100;


    std::vector<std::vector<V>> *table;

    const double loadFactor = 0.75;
    int m_size = 0;
    int capacity = 0;
    int threshold = 0;

    size_t getPosition(size_t hash, int  capacity1) const {
        return hash % capacity1;
    }

    void transfer(std::vector<std::vector<V>> *tempTable, int newCapacity) {
        for (auto a : *table)
            for (auto e : a) {
                size_t pos = getPosition(e.hash(), newCapacity);
                (*tempTable)[pos].push_back(e);
            }
    }

    void resize(int newCapacity)
    {
        if (this->capacity == MAXIMUM_CAPACITY)
        {
            threshold = 999999999;
            return;
        }

        auto tempTable = new std::vector<std::vector<V>>(newCapacity);
        capacity = newCapacity;
        transfer(tempTable, capacity);
        delete table;
        table = tempTable;
        threshold = (int)(capacity * loadFactor);
    }

public:


    HashSet(){
        capacity = DEFAULT_CAPACITY;
        threshold = (int)(capacity * loadFactor);
        table = new std::vector<std::vector<V>>(capacity);
    }


    std::vector<std::vector<V>> *getCurrent()
    {
        return table;
    }

    bool put(const V &value) {
        size_t hash = value.hash();
        int pos = getPosition(hash, capacity);
        for (auto &a : (*table)[pos])
            if (a == value)
            {
                return false;
            }
        (*table)[pos].push_back(value);
        m_size++;
        if (m_size == threshold) {
            resize(capacity * 2);
        }
        return true;
    }

    HashSet &operator<<(const V &value) {
        put(value);
        return *this;
    }

    int size() const {
        return m_size;
    }

    bool contains(V const &value) const {
        int hash = value.hash();
        int pos = getPosition(hash, capacity);
        for (auto a : (*this->table)[pos])
            if (a == value)
                return true;
        return false;
    }

    bool remove(V const &value) {
        int hash = value.hash();
        int pos = getPosition(hash, capacity);
        for (auto a = (*this->table)[pos].begin(); a != (*this->table)[pos].end(); a++)
            if (*a.hash() == hash) {
                (*this->table)[pos].erase(a);
                m_size--;
                return true;
            }
        return false;
    }

    void removeLast() {
        table->pop_back();
    }

    void addCurrent(std::vector<V> val) {
        table->push_back(val);
    }

    void clear() {
        delete table;
        capacity = DEFAULT_CAPACITY;
        table = new std::vector<std::vector<V>>(capacity);
        m_size = 0;
    }

    bool operator==(HashSet &other) const {
        //todo
        if (size() != other.size())
            return false;
        for (auto a : *table)
            for (auto e : a)
                if (!other.contains(e))
                    return false;

        for (auto a : *other.table)
            for (auto e : a)
                if (!contains(e))
                    return false;
        return true;
    }

    std::string toString() const {
        std::string s = "";
        bool first = true;
        for (auto a : *table)
            for (auto e : a) {
                if (!first)
                    s += ", ";
                first = false;
                s += e.toString() ;
            }
        return s;
    }

    void saveToFile(const std::string& filename) const
    {

        std::ofstream fs(filename, std::ios::out | std::ios::binary);
        fs.write((char *) &m_size, sizeof(m_size) );
        for (auto a : *table)
            for (auto e : a) {
                int s;
                std::string ks = e.toString();
                s = ks.size();
                fs.write((char *) &(s), sizeof(int));
                fs.write((char *) ks.c_str(), ks.size());

            }
                fs.close();
    }

    void loadFromFile(const std::string& filename)
    {
        std::ifstream fs(filename, std::ios::in | std::ios::binary);
        int newSize = 0;
        fs.read(reinterpret_cast<char *>(&newSize), sizeof(m_size) );
        for (int i = 0; i < newSize; i++) {
            int ksSize;
            fs.read((char *) &ksSize, sizeof(int));
            char* temp = new char[ksSize+1];
            fs.read((char *) temp, (ksSize));
            temp[ksSize] = '\0';
            put(V(temp));
        }
        fs.close();
    }

    bool operator[](const V& value) const {
       return contains(value);
    }

    HashSet operator &&(const HashSet<V> &other) const {
        HashSet nh;
        for (auto a : *table)
            for (auto e : a) {
                if (other[e]) {
                    nh.put(e);
                }
            }
       return nh;
    }

    ~HashSet() {
        delete table;
    }

    HashSet(const HashSet &other) {
        capacity = DEFAULT_CAPACITY;
        threshold = (int)(capacity * loadFactor);
        table = new std::vector<std::vector<V>>(capacity);
        for (const auto& a : *other.table)
            for (const auto& e : a) {
                this->put(e);
            }
    }
};


#endif //UNTITLED56_HSET_H
