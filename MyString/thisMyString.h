#pragma once
#include <iostream>

namespace thisMyString
{
    class String
    {
        public:
            String();
            String(char *STR);
            String(const String &other);
            ~String();
            void print();
            String & operator = (const String & other);
            String operator + (const String & other);
            int len();
            bool operator ==(const String & other);
            bool operator !=(const String & other);
            char & operator [] (int index);
            String(String &&other);
        
        private:
            char *str;
            int length;
    };
}
