// ConsoleApplication10.cpp : サンプル C++ コード Copyright(C) 2022 https://www.youtube.com/@ProgrammerCpp
// 参考課題：https://detail.chiebukuro.yahoo.co.jp/qa/question_detail/q13269732718
#include <iostream>
#include <iomanip>
#include <fstream>
#include <numeric>
template<class T>std::ostream& 最大限の幅で出力(std::ostream& ostm, T 値, bool 値は有効)
{
    ostm << std::setw(std::numeric_limits<decltype(値)>::digits10 + 2);
    if (値は有効)
        ostm << 値;
    else
        ostm << ' ';//無効なので空白を出力する
    return ostm;
}
int main()
{
    std::ifstream file_a{ "a.txt" };
    std::ifstream file_b{ "b.txt" };
    std::ofstream file_c{ "c.txt" };
    for (;;) {
        short aの値;
        short bの値;
        const auto aの値は有効 = (file_a >> aの値).good();
        const auto bの値は有効 = (file_b >> bの値).good();
        if (aの値は有効 || bの値は有効) {
            最大限の幅で出力(file_c, aの値, aの値は有効) << ' ';
            最大限の幅で出力(file_c, bの値, bの値は有効) << std::endl;
        }
        else
            break;
    }
}
