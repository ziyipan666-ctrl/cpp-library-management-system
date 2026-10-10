#include "../../../include/utils/FileUtil.h"
#include <fstream>
#include <string>
#include <vector>

namespace FileUtil
{
    std::vector<std::string> readAllLines(const std::string& filePath)
    {
        std::vector<std::string> result;
        std::ifstream fin(filePath);
        if (!fin.is_open())
        {
            return result;
        }
        std::string line;
        while (std::getline(fin, line))
        {
            result.push_back(line);
        }
        fin.close();
        return result;
    }

    bool writeAllLines(const std::string& filePath, const std::vector<std::string>& lines)
    {
        std::ofstream fout(filePath);
        if (!fout.is_open())
        {
            return false;
        }
        for (const std::string& s : lines)
        {
            fout << s << std::endl;
        }
        fout.close();
        return true;
    }
}