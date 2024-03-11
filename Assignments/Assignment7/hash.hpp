#include <iostream>

using std::string;

class hTable {
    private:
        
    public:
        string hashArray[10];
        hTable();
        ~hTable();
        int hash(string key);
        void insert (string key, string value);
        bool lookup (string value);
};
