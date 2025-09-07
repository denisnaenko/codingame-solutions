#include <iostream>
#include <string>

std::string DecimalToBinString(const char *ch) {
    int decimal = static_cast<int>(*ch);
    std::string msgBin;

    while (decimal != 0) {
        if (decimal % 2 == 0) {
            msgBin += "0";
        } else {
            msgBin += "1";
        }
        decimal /= 2;
    }
    while (msgBin.size() != 7) {
        msgBin += "0";
    }

    int l, r;
    l = 0;
    r = msgBin.size() - 1;
    while (l < r) {
        int temp = msgBin[l];
        msgBin[l] = msgBin[r];
        msgBin[r] = temp;

        l++; r--;
    }

    return msgBin;
}

std::string EncodeString(const std::string *msgBin) {
    std::string msgEncoded;
    int len = msgBin->length();

    int i = 0;
    while (i < len) {
        int count = 1;

        if (msgBin->at(i) == '1') {
            msgEncoded += "0 ";
            i++;

            while (i < len && msgBin->at(i) == '1') {
                i++;
                count++;
            }
        } else {
            msgEncoded += "00 ";
            i++;

            while (i < len && msgBin->at(i) == '0') {
                i++;
                count++;
            }
        }
        while (count != 0) {
            msgEncoded += "0";
            count--;
        }
        if (i < len) {
            msgEncoded += " ";
        }
    }

    return msgEncoded;
}

int main() {
    std::string msg;
    getline(std::cin, msg);

    std::string msgBin, msgEncoded;
    for (char ch : msg) {
        msgBin += DecimalToBinString(&ch);
    }

    msgEncoded = EncodeString(&msgBin);
    std::cout << msgEncoded << "\n";

    return 0;
}
