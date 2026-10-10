#ifndef LIBRARY_MANAGEMENT_SYSTEM_BOOKREPOSITORY_H
#define LIBRARY_MANAGEMENT_SYSTEM_BOOKREPOSITORY_H

#include <vector>
#include <string>
#include <memory>
#include "../entity/Book.h"

class BookRepository {
private:
    std::string filename;
    std::vector<std::shared_ptr<Book>> books;

    void loadBooks();
    void saveBooks();

public:
    BookRepository(const std::string& filename);
    ~BookRepository();

    std::shared_ptr<Book> findById(const std::string& id);
    std::shared_ptr<Book> findByIsbn(const std::string& isbn);
    std::vector<std::shared_ptr<Book>> findByTitle(const std::string& title);
    std::vector<std::shared_ptr<Book>> findByAuthor(const std::string& author);
    void addBook(const std::shared_ptr<Book>& book);
    void updateBook(const std::shared_ptr<Book>& book); // Update by ID
    void deleteBook(const std::string& id);
    std::vector<std::shared_ptr<Book>> getAllBooks() const;
};

#endif //LIBRARY_MANAGEMENT_SYSTEM_BOOKREPOSITORY_H