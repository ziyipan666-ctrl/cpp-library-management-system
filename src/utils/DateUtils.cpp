#include "DateUtil.h"

bool DateUtil::isValidDate(const string& date)
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
    return true;
}


