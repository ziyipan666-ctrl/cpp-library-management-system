#ifndef LIBRARY_MANAGEMENT_SYSTEM_BOOK_H
#define LIBRARY_MANAGEMENT_SYSTEM_BOOK_H

#include <string>

class Book {
private:
    std::string id;
    std::string title;
    std::string author;
    std::string isbn;
    int publicationYear;
    int quantity;

public:
    Book(const std::string& id, const std::string& title, const std::string& author,
         const std::string& isbn, int publicationYear, int quantity);

    std::string getId() const;
    std::string getTitle() const;
    std::string getAuthor() const;
    std::string getIsbn() const;
    int getPublicationYear() const;
    int getQuantity() const;

    void setTitle(const std::string& title);
    void setAuthor(const std::string& author);
    void setIsbn(const std::string& isbn);
    void setPublicationYear(int publicationYear);
    void setQuantity(int quantity);
};

#endif //LIBRARY_MANAGEMENT_SYSTEM_BOOK_H