#ifndef DATEUTIL_H
#define DATEUTIL_H
#include <string>
using namespace std;
// 日期工具类，处理项目中8位数字格式日期（例：20241225）
namespace DateUtil
{
    /**
     * 简单校验日期格式是否为8位纯数字
     * 待校验日期字符串
     * true格式合法，false格式非法
     */
    bool isValidDate(const string& date);
}
#endif