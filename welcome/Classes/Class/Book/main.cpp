#include <iostream>
#include <string>

class Book {
public:
    std::string title;
    std::string author;
    int year;

    // Constructor with member initializer list
    Book(const std::string& t, const std::string& a, int y)
        : title(t), author(a), year(y) {}
};

int main() {
    // Create an object of Car
    Book book1("Mathilda", "Roald Dahl", 1988);


    Book book2("The Giving Tree", "Shel Silverstein", 1964);

    std::cout << book1.title << ", " << book1.author << ", " << book1.year << "\n";
    std::cout << book2.title << ", " << book2.author << ", " << book2.year << "\n";

    return 0;
}
