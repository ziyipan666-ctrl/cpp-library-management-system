#include "../../../include/service/BookService.h"
#include <algorithm>
#include <uuid.h> // For generating UUIDs

BookService::BookService(BookRepository& bookRepository)
    : bookRepository(bookRepository)
{
}

std::vector<std::shared_ptr<Book>> BookService::getAllBooks()
{
    return bookRepository.getAllBooks();
}

bool BookService::addBook(const std::shared_ptr<Book>& book)
{
    if (bookRepository.findByIsbn(book->getIsbn())) {
        return false; // Book with same ISBN already exists
    }
    // Generate a unique ID if not already set
    if (book->getId().empty()) {
        uuids::uuid_system_generator gen;
        uuids::uuid new_uuid = gen();
        const_cast<std::string&>(book->getId()) = uuids::to_string(new_uuid); // Ugly cast, better to have a setter or generate ID in controller
    }
    bookRepository.addBook(book);
    return true;
}

bool BookService::deleteBook(const std::string& bookId)
{
    if (bookRepository.findById(bookId)) {
        bookRepository.deleteBook(bookId);
        return true;
    }
    return false;
}

bool BookService::updateBook(const std::shared_ptr<Book>& book)
{
    if (bookRepository.findById(book->getId())) {
        bookRepository.updateBook(book);
        return true;
    }
    return false;
}

std::shared_ptr<Book> BookService::queryBookById(const std::string& id)
{
    return bookRepository.findById(id);
}

std::shared_ptr<Book> BookService::queryBookByIsbn(const std::string& isbn)
{
    return bookRepository.findByIsbn(isbn);
}

std::vector<std::shared_ptr<Book>> BookService::queryBooksByTitle(const std::string& title)
{
    return bookRepository.findByTitle(title);
}

std::vector<std::shared_ptr<Book>> BookService::queryBooksByAuthor(const std::string& author)
{
    std::vector<std::shared_ptr<Book>> books = bookRepository.findByAuthor(author);
    // Sort by title alphabetically
    std::sort(books.begin(), books.end(), [](const std::shared_ptr<Book>& a, const std::shared_ptr<Book>& b) {
        return a->getTitle() < b->getTitle();
    });
    return books;
}

std::vector<std::shared_ptr<Book>> BookService::getPageData(const std::vector<std::shared_ptr<Book>>& all, int start, int count)
{
    std::vector<std::shared_ptr<Book>> page;
    int end = start + count;
    for (int i = start; i < end && i < (int)all.size(); i++)
    {
        page.push_back(all[i]);
    }
    return page;
}