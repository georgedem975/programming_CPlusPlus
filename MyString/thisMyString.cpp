#include "thisMyString.h"

namespace thisMyString
{
    String::String()
    {
        this->str = nullptr;
        this->length = 0;
    }

    String::String(char *STR)
    {
        int len = strlen(STR);
        this->str = new char[len + 1];

        for (int i = 0; i < len; i++)
        {
            this->str[i] = STR[i];
        }

        this->str[len] = '\0';

        this->length = len;
    }

    String::String(const String &other)
    {
        int len = strlen(other.str);
        this->str = new char[len + 1];

        for (int i = 0; i < len; i++)
        {
            this->str[i] = other.str[i];
        }

        this->str[len] = '\0';

        this->length = other.length;
    }

    String::~String()
    {
        delete[] this->str;
    }

    void String::print()
    {
        std::cout << this->str;
    }

    String &String::operator=(const String &other)
    {
        if (this->str != nullptr)
        {
            delete[] this->str;
        }

        int len = strlen(other.str);
        this->str = new char[len + 1];

        for (int i = 0; i < len; i++)
        {
            this->str[i] = other.str[i];
        }

        this->str[len] = '\0';

        this->length = other.length;

        return *this;
    }

    String String::operator+(const String &other)
    {
        String temp;

        temp.length = strlen(this->str) + strlen(other.str);

        temp.str = new char[strlen(this->str) + strlen(other.str) + 1];

        for (int i = 0; i < strlen(this->str); i++)
        {
            temp.str[i] = this->str[i];
        }

        for (int j = 0; j < strlen(other.str); j++)
        {
            temp.str[j + strlen(this->str)] = other.str[j];
        }

        temp.str[strlen(this->str) + strlen(other.str)] = '\0';

        return temp;
    }

    int String::len()
    {
        return this->length;
    }

    bool String::operator==(const String &other)
    {
        if (this->length != other.length)
        {
            return false;
        }

        for (int i = 0; i < this->length; i++)
        {
            if (this->str[i] != other.str[i])
            {
                return false;
            }
        }

        return true;
    }

    bool String::operator!=(const String &other)
    {
        return !(this->operator==(other));
    }

    char &String::operator[](int index)
    {
        return this->str[index];
    }

    String::String(String &&other)
    {
        this->length = other.length;
        this->str = other.str;

        other.str = nullptr;
    }
}