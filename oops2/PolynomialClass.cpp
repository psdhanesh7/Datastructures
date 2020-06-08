#include <vector>
#include <climits>
#include <iostream>
using namespace std;

class Polynomial {
	

	public :

		int *degCoeff;
		int size;
		
		Polynomial() {
			degCoeff = new int[10]();
			size = 10;
		}

		~Polynomial() {
			delete [] degCoeff;
			size = 0;
		}

		Polynomial(Polynomial const &p) {
			size = p.size;
			degCoeff = new int[size];

			for(int i = 0; i < size; i++) {
				degCoeff[i] = p.degCoeff[i];
			}
		}

		void setCoefficient(int degree, int coeff) {
			if(degree >= size) {
				int *newDegCoeff = new int[degree + 1]();
				// size = degree + 1;

				for(int i = 0; i < size; i++) {
					newDegCoeff[i] = degCoeff[i];
				}
                
                delete [] degCoeff;
                degCoeff = newDegCoeff;
                size = degree + 1;
			}

			degCoeff[degree] = coeff;
		}

		Polynomial operator+(Polynomial const &p2) const {
			Polynomial p3;
			int i = 0;

			while(i < this->size && i < p2.size) {
				p3.setCoefficient(i, this->degCoeff[i] + p2.degCoeff[i]);
				i++;
			}

			while(i < this->size) {
				p3.setCoefficient(i, this->degCoeff[i]);
                i++;
			}
			while(i < p2.size) {
				p3.setCoefficient(i, p2.degCoeff[i]);
                i++;
			}

			return p3;
		}

		Polynomial operator-(Polynomial const &p2) const {

			Polynomial p3;
			int i = 0;

			while(i < this->size && i < p2.size) {
				p3.setCoefficient(i, this->degCoeff[i] - p2.degCoeff[i]);
				i++;
			}

			while(i < this->size) {
				p3.setCoefficient(i, this->degCoeff[i]);
                i++;
			}
			while(i < p2.size) {
				p3.setCoefficient(i, p2.degCoeff[i]);
                i++;
			}

			return p3;
		}

		Polynomial operator*(Polynomial const &p2) const{

			Polynomial p3;
			for(int i = 0; i < size; i++) {
				if(degCoeff[i] != 0) {
					for(int j = 0; j < p2.size; j++) {
						// cout << i+j << ":" << degCoeff[i] * p2.degCoeff[j] << endl;
	                    if(i+j < p3.size) {
							p3.setCoefficient(i+j, (degCoeff[i] * p2.degCoeff[j]) + p3.degCoeff[i+j]);
						}
						else {
							p3.setCoefficient(i+j, degCoeff[i] * p2.degCoeff[j]);
						}
					}
				}
				
			}

			return p3;
		}

		void operator=(Polynomial const &p2) {
			for(int i = 0; i < p2.size; i++) {
				setCoefficient(i, p2.degCoeff[i]);
			}
		}


		void print() const {
			for(int i = 0; i < size; i++) {
				if(degCoeff[i] != 0) {
					cout << degCoeff[i] << "x" << i << " ";
				}
			}
			cout << endl;
		}


};

/* C++ implementation to convert infix expression to postfix*/
// Note that here we use std::stack  for Stack operations




//Driver program to test above functions
int main()
{
    int count1,count2,choice;
    cin >> count1;
    
    int *degree1 = new int[count1];
    int *coeff1 = new int[count1];
    
    for(int i=0;i < count1; i++) {
        cin >> degree1[i];
    }
    
    for(int i=0;i < count1; i++) {
        cin >> coeff1[i];
    }
    
    Polynomial first;
    for(int i = 0; i < count1; i++){
        first.setCoefficient(degree1[i],coeff1[i]);
    }
    
    cin >> count2;
    
    int *degree2 = new int[count2];
    int *coeff2 = new int[count2];
    
    for(int i=0;i < count2; i++) {
        cin >> degree2[i];
    }
    
    for(int i=0;i < count2; i++) {
        cin >> coeff2[i];
    }
    
    Polynomial second;
    for(int i = 0; i < count2; i++){
        second.setCoefficient(degree2[i],coeff2[i]);
    }
    
    cin >> choice;
    
    switch(choice){
            // Add
        case 1:
        {
            Polynomial result1 = first + second;
            result1.print();
            break;
        }
            // Subtract
        case 2 :
        {
            Polynomial result2 = first - second;
            result2.print();
            break;
        }
            // Multiply
        case 3 :
        {
            Polynomial result3 = first * second;
            result3.print();
            break;
        }
        case 4 : // Copy constructor
        {
            Polynomial third(first);
            if(third.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
        case 5 : // Copy assignment operator
        {
            Polynomial fourth(first);
            if(fourth.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
    }

    delete [] degree1;
    delete [] degree2;
    delete [] coeff1;
    delete [] coeff2;
    
    return 0;
}
