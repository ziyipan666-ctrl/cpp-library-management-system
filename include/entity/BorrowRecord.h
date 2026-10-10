#ifndef LIBRARY_MANAGEMENT_SYSTEM_BORROWRECORD_H
#define LIBRARY_MANAGEMENT_SYSTEM_BORROWRECORD_H

#include <string>

class BorrowRecord {
private:
    std::string id;
    std::string bookId;
    std::string userId;
    std::string borrowDate; // Consider using a proper date/time type if available
    std::string returnDate; // Consider using a proper date/time type if available

public:
    BorrowRecord(const std::string& id, const std::string& bookId, const std::string& userId,
                 const std::string& borrowDate, const std::string& returnDate = "");

    std::string getId() const;
    std::string getBookId() const;
    std::string getUserId() const;
    std::string getBorrowDate() const;
    std::string getReturnDate() const;

    void setReturnDate(const std::string& returnDate);
};

#endif //LIBRARY_MANAGEMENT_SYSTEM_BORROWRECORD_H