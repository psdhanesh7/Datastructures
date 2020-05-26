// *********
 
// Following is the main function we are using internally.
// Refer this for completing the ComplexNumbers class.
 

#include<iostream>
using namespace std;


class ComplexNumbers {
    // Complete this class
    private :
    
        int real;
        int imaginary;

    public : 

        ComplexNumbers(int real, int imaginary) {

            this->real = real;
            this->imaginary = imaginary;
        }

        void plus(ComplexNumbers const &c2) {

            real = real + c2.real;
            imaginary = imaginary + c2.imaginary;
        }

        void multiply(ComplexNumbers const &c2) {

            int a1 = real;
            int a2 = c2.real;

            int b1 = imaginary;
            int b2 = c2.imaginary;

            int real = a1*a2 - b1*b2;
            int imaginary = a1*b2 + a2*b1;

            this->real = real;
            this->imaginary = imaginary;
        }

        void print() {
            cout << real << " + i" << imaginary << endl;
        }
        
    
};
 
int main() {
    int real1, imaginary1, real2, imaginary2;
    
    cin >> real1 >> imaginary1;
    cin >> real2 >> imaginary2;
    
    ComplexNumbers c1(real1, imaginary1);
    ComplexNumbers c2(real2, imaginary2);
    
    int choice;
    cin >> choice;
    
    if(choice == 1) {
        c1.plus(c2);
        c1.print();
    }
    else if(choice == 2) {
        c1.multiply(c2);
        c1.print();
    }
    else {
        return 0;
    }
    
}
 
 // ***********


