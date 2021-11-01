#ifndef UTILS_H_
#define UTILS_H_

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <stdio.h>
#include <vector>
#include <random>

using std::string;
using std::random_device;
using std::default_random_engine;

inline string strRand(int length) {			// length: 产生字符串的长度
    char tmp;							// tmp: 暂存一个随机数
    string buffer;						// buffer: 保存返回值
    
    // 下面这两行比较重要:
    random_device rd;					// 产生一个 std::random_device 对象 rd
    default_random_engine random(rd());	// 用 rd 初始化一个随机数发生器 random
    
    for (int i = 0; i < length; i++) {
        tmp = random() % 36;	// 随机一个小于 36 的整数，0-9、A-Z 共 36 种字符
        if (tmp < 10) {			// 如果随机数小于 10，变换成一个阿拉伯数字的 ASCII
            tmp += '0';
        } else {				// 否则，变换成一个大写字母的 ASCII
            tmp -= 10;
            tmp += 'A';
        }
        buffer += tmp;
    }
    return buffer;
}

inline string strRandHex(int length) {			// length: 产生字符串的长度
    char tmp;							// tmp: 暂存一个随机数
    string buffer;						// buffer: 保存返回值
    
    // 下面这两行比较重要:
    random_device rd;					// 产生一个 std::random_device 对象 rd
    default_random_engine random(rd());	// 用 rd 初始化一个随机数发生器 random
    
    for (int i = 0; i < length; i++) {
        tmp = random() % 16;	// 随机一个小于 36 的整数，0-9、A-Z 共 36 种字符
        if (tmp < 10) {			// 如果随机数小于 10，变换成一个阿拉伯数字的 ASCII
            tmp += '0';
        } else {				// 否则，变换成一个大写字母的 ASCII
            tmp -= 10;
            tmp += 'A';
        }
        buffer += tmp;
    }
    return buffer;
}

inline std::string intToHex(int input){
    std::stringstream stream;
    stream << std::hex << input;
    std::string result( stream.str() );
    return result;
}

inline std::vector<uint8_t> HexToBytes(const std::string &hex) {
    std::vector<uint8_t> bytes;
    for (unsigned int i = 0; i < hex.length(); i += 2) {
        std::string byteString = hex.substr(i, 2);
        uint8_t byte = strtol(byteString.data(), nullptr, 16);
        bytes.push_back(byte);
    }
    return bytes;
}

inline std::string BytesToHex(std::vector<uint8_t> data)
{
     std::stringstream ss;
     ss << std::setfill('0') << std::hex;

     for( int i(0) ; i < data.size(); ++i )
         ss << std::setw(2) << (unsigned int)data[i];

     return ss.str();
}

inline std::string BytesToHex(const uint8_t *v, const size_t s) {
    std::stringstream ss;

    ss << std::hex << std::setfill('0');

    for (int i = 0; i < s; i++) {
        ss<<std::setw(2)<<static_cast<int>(v[i]);
    }
    return ss.str();
}

#endif