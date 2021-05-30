#include<iostream>
#include <string.h>

using namespace std;

struct BigNum {
	char sign;
	char num[101];
	BigNum() {
		sign = '1';
		for (int i=0; i < 101; i++){
			num[i] = '0';
		}
	}
};

ostream& operator<< (std::ostream& out, const BigNum& num)
{
    out << num.sign;
    int index = 100;
    while (num.num[index] == '0')
        --index;
    while (index >= 0)
    {
        out << num.num[index];
        --index;
    }
    return out;
}

istream& operator>> (std::istream& in, BigNum& num)
{
    char temp[102];
    in >> temp;
    int length = strlen(temp);
    num.sign = temp[0];
    for (int i = length - 1; i > 0; --i)
    {
        num.num[length - i - 1] = temp[i];
    }
    return in;
}

void Add(const BigNum& num1, const BigNum& num2, BigNum& res)
{
    res.sign = num1.sign;
    int carry = 0;
    int sum = 0;
    for (int i = 0; i < 101; ++i)
    {
        sum = num1.num[i] + num2.num[i] + carry - 2 * '0';
        res.num[i] = sum % 10 + '0';
        carry = sum / 10;
    }
}

void Subtract(const BigNum& num1, const BigNum& num2, BigNum& res)
{
    res.sign = num1.sign;
    int carry = 0;
    int sum = 0;
    for (int i = 0; i < 101; ++i)
    {
        sum = num1.num[i] - num2.num[i] - carry;
        if (sum >= 0)
        {
            res.num[i] = sum + '0';
            carry = 0;
        }
        else
        {
            res.num[i] = sum + 10 + '0';
            carry = 1;
        }
    }
}

int CompareAbsoluteValue(const BigNum& num1, const BigNum& num2)
{
    for (int i = 100; i >= 0; --i)
    {
        if (num1.num[i] > num2.num[i])
            return 1;
        else if (num1.num[i] < num2.num[i])
            return -1;
    }
    return 0;
}

BigNum operator+ (const BigNum& num1, const BigNum& num2)
{
    BigNum res;
    if (num1.sign == num2.sign)
    {
        Add(num1, num2, res);
        return res;
    }
    
    int comparisonResult = CompareAbsoluteValue(num1, num2);
    if (comparisonResult > 0)
    {
        Subtract(num1, num2, res);
    }
    else if (comparisonResult < 0)
    {
        Subtract(num2, num1, res);
    }
    return res;
}

void Multiply(const BigNum& num1, int num2, int numOfZero, BigNum& res)
{
    if (num2 == 0)
        return;
    int carry = 0;
    int product = 0;
    for (int i = 0; i < numOfZero; ++i)
    {
        res.num[i] = '0';
    }
    for (int i = numOfZero; i < 101; ++i)
    {
        product = (num1.num[i - numOfZero] - '0') * num2 + carry;
        res.num[i] = product % 10 + '0';
        carry = product / 10;
    }
}

void Multiply(const BigNum& num1, const BigNum& num2, BigNum& res)
{
    for (int i = 0; i < 101; ++i)
    {
        if (num2.num[i] != '0')
        {
            BigNum term;
            Multiply(num1, num2.num[i] - '0', i, term);
            Add(res, term, res);
        }
    }
    if (num1.sign == num2.sign)
        res.sign = num1.sign;
    else
        res.sign = '0';
}

BigNum operator* (const BigNum& num1, const BigNum& num2)
{
    BigNum res;
    Multiply(num1, num2, res);
    return res;
}

BigNum operator- (const BigNum& num1, const BigNum& num2)
{
    BigNum res;
    // Create a BigNum that is opposite to num2
    BigNum num2Op = num2;
    num2Op.sign = (num2.sign == '1') ? '0' : '1';
    res = num1 + num2Op;
    return res;
}

BigNum operator* (int num2, const BigNum& num1)
{
    if (num2 == 1)
        return num1;
    BigNum res;
    if (num2 == 0)
        return res;
    // Convert int to BigNum
    BigNum num2BigNum;
    num2BigNum.sign = (num2 >= 0) ? '1' : '0';
    if (num2 < 0) num2 *= -1;
    int index = 0;
    while (num2 > 0)
    {
        num2BigNum.num[index] = num2 % 10 + '0';
        num2 /= 10;
        ++index;
    }
    return num1 * num2BigNum;
}


int main()
{
	printf("Le Trong Khanh - 20194082\n\n");

    BigNum a;
    cin >> a;

    BigNum b;
    cin >> b;

    cout << a * b - 3 * a + 4 * b;
    
    return 0;
}
