//
// Created by ankolesn on 23.07.22.
//

#include "notebook.hpp"

void Notebook::add(const std::string &name, unsigned int phone) {
    std::lock_guard<std::mutex> m(mtx);
    nt.insert(std::pair<std::string, unsigned int> (name, phone));
}

void Notebook::erase(const std::string &name) {
    std::lock_guard<std::mutex> m(mtx);
    nt.erase(name);
}

std::string &Notebook::find(unsigned int phone) {
    std::lock_guard<std::mutex> m(mtx);
    for (auto &i: nt) {
        if (i.second == phone)
            return const_cast<std::string &>(i.first);
    }
    throw (std::invalid_argument("Not found"));
}

void Notebook::load(const std::string &filename) {
    std::ifstream file(filename);
    std::string name;
    unsigned int phone;
    while (file >> name >> phone) {
        add(name, phone);
    }
    file.close();
}

void Notebook::save(const std::string &filename) {
    std::lock_guard<std::mutex> m(mtx);
    std::ofstream file(filename);
    for (auto &i: nt) {
        file << "Name: " << i.first << " " << "Phone: " << i.second << std::endl;
    }
    file.close();
}

std::ostream &operator<<(std::ostream &out, const Notebook &nt) {
    for (auto &i: nt.nt) {
        out << "Name: " << i.first << " " << "Phone: " << i.second << std::endl;
    }
    return out;
}

