#pragma once
#include <iostream>
#include<math.h>
#include<algorithm>


class Byte {
    char m_data;
public:
    enum class NumberSystem {
        Binary,
        Decimal,
        Hex,
        Octal
    };
    enum class Direction {
        Left,
        Right
    };

    Byte() :
        m_data(0)
    {

    }

    Byte(const char& data) :
        m_data(data)
    {

    }

    Byte(const Byte& data) :
        m_data(data.m_data)
    {

    }

    Byte(std::string data, const NumberSystem& numberSystem = NumberSystem::Binary) :
        m_data(0)
    {
        switch (numberSystem)
        {
        case NumberSystem::Binary:
        {
            unsigned int i = 0;
            reverse(data.begin(), data.end());
            while (i < 8 && i < data.length())
            {
                if (data[i] == '1')
                {
                    m_data = m_data + (char)pow(2, i);
                }
                i++;
            }
        }
        break;

        case NumberSystem::Decimal:
        {

        }
        break;
        }

    }

    unsigned int bit(const unsigned int& i) {
        if (i < 1 || i > 8) {
            return 0;
        }
        char temp = m_data;
        if (temp >> (i - 1) & 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    void rotate(const int& i, const Direction& direction = Direction::Left)
    {
        if (direction == Direction::Left)
        {
            m_data = (m_data << i) | (m_data >> (8 - i));
        }
        else
        {
            m_data = (m_data >> i) | (m_data << (8 - i));
        }
    }

    void shift(const Direction& direction, const int& i)
    {
        if (direction == Direction::Left)
        {
            m_data = m_data << i;
        }
        else
        {
            m_data = m_data >> i;
        }

    }

    void leftShift(const int& i)
    {
        m_data = m_data << i;
    }

    void rightShift(const int& i)
    {
        m_data = m_data >> i;
    }

    void operator<<(const int& i) {
        m_data = m_data << i;
    }

    void operator>>(const int& i) {
        m_data = m_data >> i;
    }

    Byte operator+(const Byte& byte)
    {
        return Byte(m_data + byte.m_data);
    }

    Byte operator-(const Byte& byte)
    {
        return Byte(m_data - byte.m_data);
    }

    Byte operator/(const Byte& byte)
    {
        return Byte(m_data / byte.m_data);
    }

    Byte operator*(const Byte& byte)
    {
        return Byte(m_data * byte.m_data);
    }

    Byte operator%(const Byte& byte)
    {
        return Byte(m_data % byte.m_data);
    }

    Byte operator|(const Byte& byte)
    {
        return Byte(m_data | byte.m_data);
    }

    Byte operator&(const Byte& byte)
    {
        return Byte(m_data & byte.m_data);
    }

    Byte operator^(const Byte& byte)
    {
        return Byte(m_data ^ byte.m_data);
    }

    friend  std::ostream& operator<<(std::ostream& os, const Byte& byte);
};

std::ostream& operator<<(std::ostream& os, const Byte& byte)
{
    char temp = byte.m_data;
    for (int i = 8; i > 0; i--)
    {
        os << ((temp >> (i - 1)) & 1);
    }
    return os;
}