#include <iostream>
using namespace std;

class QuadEquan {
    private:
    double a, b, c;

    public:
    QuadEquan (double a, double b, double c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }
    QuadEquan() {}

    friend ostream& operator<<(ostream& os, const QuadEquan& k) {
        os <<k.a << "x^2 + " << k.b << "x + " << k.c;
        return os;
    }
    friend istream& operator>>(istream& is, QuadEquan& k) {
        is >> k.a >> k.b >> k.c;
        return is;
    }

    QuadEquan operator+( const QuadEquan& other) const {
        return QuadEquan( a + other.a, b + other.b, c + other.c );
    }
    QuadEquan operator-( const QuadEquan& other) const {
        return QuadEquan( a - other.a, b - other.b, c - other.c );
    }

    double operator()(double x) const {
        return a * x * x + b * x + c;
    }

    bool operator==( const QuadEquan& other) const {
        return a == other.a && b == other.b && c == other.c;
    }
};

int main () {
    QuadEquan equantity1(8.3, 9.1, 2.2);
    QuadEquan equantity2(3, 7, 2.5);

    cout<< "Fist equantity: " << equantity1 <<endl;
    cout<< "Second equantity: " << equantity2 <<endl;

    cout<<endl;

    cout<< "The sum : " << equantity1 + equantity2 << endl;
    cout<< "The difference : " << equantity1 - equantity2 << endl;

    cout<<endl;
    
    cout<< "Value in point, first equantity : " << equantity1(2.9)<<endl;
    cout<< "Value in point, second equantity : " << equantity2(3)<<endl;

    return 0;
}