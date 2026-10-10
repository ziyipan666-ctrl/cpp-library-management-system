#include "../../../include/utils/DateUtil.h"
#include <string>
#include <ctime> // For time_t, tm, localtime, strftime

namespace DateUtil
{
    bool isValidDate(const std::string& date)
    {
        // 判断长度必须等于8
        if (date.size() != 8)
        {
            return false;
        }
        // 判断每一位都是数字
        for (char ch : date)
        {
            if (!isdigit(ch))
            {
                return false;
            }
        }
        // TODO: More robust date validation (e.g., month range, day range)
        return true;
    }

    std::string getCurrentDate()
    {
        time_t now = time(0);
        tm* ltm = localtime(&now);

        char buffer[9]; // YYYYMMDD\0
        strftime(buffer, sizeof(buffer), "%Y%m%d", ltm);
        return std::string(buffer);
    }
}