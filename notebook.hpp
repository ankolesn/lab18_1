//
// Created by ankolesn on 23.07.22.
//

#ifndef LAB18_1_NOTEBOOK_HPP
#define LAB18_1_NOTEBOOK_HPP
#include <string>
#include <map>
#include <fstream>
#include <mutex>

class Notebook {
private:
    std::multimap<std::string, unsigned int> nt;
    std::mutex mtx;

public:
    void add(const std::string &name, unsigned phone);

    void erase(const std::string &name);

    std::string& find(unsigned phone);

    void load(const std::string& filename);

    void save(const std::string& filename);

    friend std::ostream& operator<<(std::ostream& out, const Notebook& nt);
};


#endif //LAB18_1_NOTEBOOK_HPP
