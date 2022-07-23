#include <iostream>
#include "notebook.hpp"
#include <thread>
#include <mutex>

void add_data(Notebook& nb){
    nb.add("aaa", 123);
    nb.add("bbb", 321);
    nb.add("ccc", 456);
    nb.add("ccc", 878);
}


int main() {
    Notebook nb;

    std::thread tr1([&]() { add_data(nb); });
    nb.erase("aaa");

    nb.load("file.txt");
    std::cout << nb;
    nb.save("file2.txt");
    tr1.join();
}
