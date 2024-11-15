#include <iostream>

class Fraction {
private:
    int numerator;   
    int denominator;

public:

    Fraction(int num = 0, int denom = 1) : numerator(num), denominator(denom) {
        if (denom == 0) {
            std::cerr << "Error: Denominator cannot be zero! Setting to 1." << std::endl;
            denominator = 1;
        }
    }

    void input() {
        std::cout << "Enter numerator and denominator: ";
        std::cin >> numerator >> denominator;
        if (denominator == 0) {
            std::cerr << "Error: Denominator cannot be zero! Setting to 1." << std::endl;
            denominator = 1;
        }
    }

    void display() const {
        std::cout << numerator << "/" << denominator << "\n";
    }

    Fraction add(const Fraction& other) const {
        return Fraction(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator);
    }

    Fraction subtract(const Fraction& other) const {
        return Fraction(numerator * other.denominator - other.numerator * denominator, denominator * other.denominator);
    }

    Fraction multiply(const Fraction& other) const {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }

    Fraction divide(const Fraction& other) const {
        if (other.numerator == 0) {
            std::cerr << "Error: Cannot divide by zero! Returning original fraction.\n";
            return *this;
        }
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }
};

int main() {
    Fraction f1, f2;
    std::cout << "Enter first fraction:\n";
    f1.input();
    std::cout << "Enter second fraction:\n";
    f2.input();

    Fraction sum = f1.add(f2);
    Fraction diff = f1.subtract(f2);
    Fraction prod = f1.multiply(f2);
    Fraction quot = f1.divide(f2);

    std::cout << "Sum: "; sum.display();
    std::cout << "Difference: "; diff.display();
    std::cout << "Product: "; prod.display();
    std::cout << "Quotient: "; quot.display();

    return 0;
}
