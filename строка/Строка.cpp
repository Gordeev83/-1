#include <iostream>
#include <cstring>

class String {
private:
    int length;
    char* str;
public:
    String(const char* s)
    {
        length = strlen(s);
        str = new char[length + 1];
        strcpy_s(str, 255, s);
    }
    String(int len)
    {
        length = len;
        str = new char[length + 1];
        str[0] = '\0';
    }
    String(const String& other)
    {
        length = other.length;
        str = new char[length + 1];
        strcpy_s(str,255, other.str);
    }
    ~String()
    {
        delete[] str;
    }
    void print() {
        std::cout << str << std::endl;
    }
    void set(const char* s) {
        int len = strlen(s);
        if (len > length) {
            delete[] str;
            length = len;
            str = new char[length + 1];
        }
        strcpy_s(str, 255, s);
    }
};

int main()
{
    String s1("Hello");
    s1.print();  // Output: Hello

    String s2(10);
    s2.set("World");
    s2.print();  // Output: World

    String s3 = s1;
    s3.print();  // Output: Hello

    return 0;
}