#include "Fraction.hpp"



void Fraction::reduce() {
    if (denominator == 0) {
        throw Exception("Denominator cannot be zero");

    }
    else {
        size_t comm = std::gcd(numerator, denominator);
       this-> numerator /= comm;
       this-> denominator /= comm;
        if (this->denominator < 0) {
            this->numerator *= -1;
            this->denominator *= -1;
        }
    }
}



Fraction::Fraction() : numerator(0), denominator(1) {}

Fraction::Fraction(int64_t num, int64_t denom) : numerator(num), denominator(denom) {
    if (denom == 0){
        throw Exception("Denominator cannot be zero");
    }
    reduce();
   
}

Fraction::Fraction(const Fraction& other) : numerator(other.numerator), denominator(other.denominator) {}

Fraction::~Fraction() {}

Fraction& Fraction::operator=(const Fraction& other) {
    if (this != &other) {
        numerator = other.numerator;
        denominator = other.denominator;
    }
    return *this;
}

Fraction Fraction::operator+(const Fraction& other) const {
    int64_t num = numerator * other.denominator + other.numerator * denominator;
    int64_t denom = denominator * other.denominator;
    return Fraction(num,denom);
}

Fraction Fraction::operator-(const Fraction& other) const {
    int64_t num = numerator * other.denominator - other.numerator * denominator;
    int64_t denom = denominator * other.denominator;
    return Fraction(num,denom);

}

Fraction Fraction::operator*(const Fraction& other) const {
    int64_t num = numerator * other.numerator;
    int64_t denom = denominator * other.denominator;
    return Fraction(num,denom);

}

Fraction Fraction::operator/(const Fraction& other) const {
    if (other.numerator == 0)
        throw Exception("Division by zero");
    int64_t num = numerator * other.denominator;
    int64_t denom = denominator * other.numerator;
    return Fraction(num,denom);

}

bool Fraction::operator==(const Fraction& other) const {
    return (numerator == other.numerator) && (denominator == other.denominator);
}

bool Fraction::operator!=(const Fraction& other) const {
    return !(*this == other);
}

bool Fraction::operator<(const Fraction& other) const {
    return (numerator * other.denominator) < (other.numerator * denominator);
}

bool Fraction::operator>(const Fraction& other) const {
    return (numerator * other.denominator) > (other.numerator * denominator);
}

bool Fraction::operator<=(const Fraction& other) const {
    return !(*this > other);
}

bool Fraction::operator>=(const Fraction& other) const {
    return !(*this < other);
}

Fraction& Fraction::operator++() {
    numerator += denominator;
    return *this;
}

Fraction Fraction::operator++(int) {
    Fraction temp = *this;
    ++(*this);
    return temp;
}

Fraction& Fraction::operator--() {
    numerator -= denominator;
    return *this;
}

Fraction Fraction::operator--(int) {
    Fraction temp = *this;
    --(*this);
    return temp;
}

Fraction Fraction::operator-() const {
    return Fraction(-numerator, denominator);
}

Fraction Fraction::operator!() const {
    if (numerator == 0)
        throw Exception("Inverse of zero is undefined");
    return Fraction(denominator, numerator);
}

std::istream& operator>>(std::istream& in, Fraction& fraction) {
    in >> fraction.numerator ;
    if(!in>>fraction.numerator){
        throw Exception("You did not enter a number");
    }
    char slash;

    in >> slash;
    if((!in>>fraction.numerator)&& slash!='/'){
        throw Exception("You did not enter a /");
    }

    in >> fraction.denominator ;
    if(!in>>fraction.denominator){
        throw Exception("You did not enter a number");
    }

    if (fraction.denominator == 0)
        throw Exception("Denominator cannot be zero");
   
    return in;
}


std::ostream& operator<<(std::ostream& out, const Fraction& fraction) {
    out << fraction.numerator << '/' << fraction.denominator;
    return out;
}

Fraction::operator double() const {
    return static_cast<double>(numerator) / denominator;
}


Fraction& Fraction::operator+=(const Fraction& other) {
    int64_t commonDenom = denominator * other.denominator;
    int64_t newNumerator = numerator * other.denominator + other.numerator * denominator;
    numerator = newNumerator;
    denominator = commonDenom;
    reduce();
    return *this;
}

Fraction &Fraction::operator-=(const Fraction& other)
{

    int64_t newDenom = denominator * other.denominator;
    int64_t newNumerator = numerator * other.denominator - other.numerator * denominator;
    reduce();
    return *this;
}


Fraction& Fraction::operator*=(const Fraction& other) {
    numerator *= other.numerator;
    denominator *= other.denominator;
    reduce();
    return *this;
}

Fraction& Fraction::operator/=(const Fraction& other) {
    if (other.numerator == 0) {
        throw Exception("Division by zero");
    }
    numerator *= other.denominator;
    denominator *= other.numerator;
    reduce();
    return *this;
}

