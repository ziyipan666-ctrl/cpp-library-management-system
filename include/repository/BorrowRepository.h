#ifndef LIBRARY_MANAGEMENT_SYSTEM_BORROWREPOSITORY_H
#define LIBRARY_MANAGEMENT_SYSTEM_BORROWREPOSITORY_H

#include <vector>
#include <string>
#include <memory>
#include "../entity/BorrowRecord.h"

class BorrowRepository {
private:
    std::string filename;
    std::vector<std::shared_ptr<BorrowRecord>> records;

    void loadRecords();
    void saveRecords();

public:
    BorrowRepository(const std::string& filename);
    ~BorrowRepository();

    std::shared_ptr<BorrowRecord> findById(const std::string& id);
    std::vector<std::shared_ptr<BorrowRecord>> findByBookId(const std::string& bookId);
    std::vector<std::shared_ptr<BorrowRecord>> findByUserId(const std::string& userId);
    void addRecord(const std::shared_ptr<BorrowRecord>& record);
    void updateRecord(const std::shared_ptr<BorrowRecord>& record); // Update by ID
    void deleteRecord(const std::string& id);
    std::vector<std::shared_ptr<BorrowRecord>> getAllRecords() const;
};

#endif //LIBRARY_MANAGEMENT_SYSTEM_BORROWREPOSITORY_H