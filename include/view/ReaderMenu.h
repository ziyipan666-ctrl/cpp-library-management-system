#ifndef READERMENU_H
#define READERMENU_H
#include "ReaderController.h"
using namespace std;

/**
 * @brief 读者菜单视图：读者所有操作界面
 */
class ReaderMenu {
private:
    ReaderController& readerCtrl;
public:
    ReaderMenu(ReaderController& ctrl);
    void showReaderLoop();

private:
    void menuBorrowBook();        //借书
    void menuReturnBook();        //还书
    void menuSearchBook();        //查询图书
    void menuShowRank();          //借阅排行榜
    void menuDeleteSelfAccount(); //删除本人账号
    void menuShowBorrowHistory(); //查看借阅历史
    void menuBrowseAllBook();     //浏览全部图书
};
#endif
