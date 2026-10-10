#ifndef LIBRARY_MANAGEMENT_SYSTEM_READER_H
#define LIBRARY_MANAGEMENT_SYSTEM_READER_H

#include "User.h"

class Reader : public User {
private:
    int borrowedBookCount;

public:
    Reader(const std::string& id, const std::string& username, const std::string& password, int borrowedBookCount = 0);

    int getBorrowedBookCount() const;
    void setBorrowedBookCount(int count);
    void incrementBorrowedBookCount();
    void decrementBorrowedBookCount();
};

#endif //LIBRARY_MANAGEMENT_SYSTEM_READER_H