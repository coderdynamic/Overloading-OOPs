//Overloading the cin, cout, arithmetic and pre-post operator

#include<iostream>
using namespace std;

class Complex
{
	public:

	friend ostream& operator << (ostream& tempout, Complex& tempc);
	friend istream& operator >> (istream& tempin, Complex& tempc);
	friend Complex& operator * (int,Complex);
	friend Complex& operator / (int,Complex);
	friend Complex& operator * (Complex,Complex);

	//real and imaginary parts of a complex number
	double real;
	double imag;

	//constructor
	Complex():real(0.0), imag(0.0)
	{   }

	//set the value of variables
	void setValue(double r, double i)
	{
		real=r;
		imag=i;
	}

	//print the complex numbers
	void showComplex()
	{
		cout<<real<<" +i "<<imag<<endl;
	}

	//pre increment operator overloading function
	Complex& operator ++()
	{
		real=real+1;
		return *this;
	}

	//pre decrement operator overloading function
	Complex& operator --()
	{
		real=real-1;
		return *this;
	}


	//post decrement operator overloading function
	Complex& operator --(int)
	{
		static Complex temp1 ;
		temp1.real=real;
		temp1.imag=imag;
		real=real-1;
		return temp1;
	}

	//post increment operator overloading function
	Complex& operator ++(int)
	{
		static Complex temp ;
		temp.real=real;
		temp.imag=imag;
		real=real+1;
		return temp;
	}
	//Destructor
	~Complex()
	{   }

};



	//1. operator '*' overloading function
	Complex& operator * (int x, Complex t1)
	{
		t1.real*=x;
		t1.imag*=x;
	}

	//1. operator '/' overlaoding function
	Complex& operator / (int y, Complex t2)
	{
		t2.real/=y;
		t2.imag/=y;
	}

	//2.operator '+' overloading function
	Complex& operator + (int z,Complex t)
	{
		t.real+=z;
	}

	//2.operator '-' overloading function
	Complex& operator - (int z,Complex t)
	{
		t.real-=z;
	}

	//3.operator '+' overloading function
	Complex& operator + (Complex t,int z)
	{
		t.real+=z;
	}

	//3.operator '-' overloading function
	Complex& operator - (Complex t2,int p)
	{
		t2.real-=p;
	}

	//4. operator '*' overloading function
	Complex& operator * (Complex t1,int x)
	{
		t1.real*=x;
		t1.imag*=x;
	}

	//4. operator '/' overlaoding function
	Complex& operator / (Complex t2, int y)
	{
		t2.real/=y;
		t2.imag/=y;
	}

	//5. operator '*' overloading function with two objects
	Complex& operator * (Complex a, Complex b)
	{
		Complex c;
		c.real=(a.real*b.real) - (a.imag*b.imag);
		c.imag=(a.real*b.imag) + (b.real*a.imag);
	}

	//6. operator '+' overloading function with two objects
	Complex& operator + (Complex a, Complex b)
	{
		Complex c;
		c.real=a.real + b.real;
		c.imag=b.imag + a.imag;
	}

	//6. operator '-' overloading function with two objects
	Complex& operator - (Complex a, Complex b)
	{
		Complex c;
		c.real=a.real - b.real;
		c.imag=a.imag - b.imag;
	}

    // '<<' operator overloading function
    ostream& operator << (ostream& tempout, Complex& tempc)
    {
        tempout<<tempc.real;
        cout<<"+i";
        tempout<<tempc.imag;
        return tempout;
    }

    // '>>' operator overloading function
    istream& operator >> (istream& tempin, Complex& tempc)
    {
        tempin>>tempc.real;
        tempin>>tempc.imag;
        return tempin;
    }

int main(void)
{
	Complex c1,c2,c3,c4;//class objects
	cout<<"Enter the first complex number:"<<endl;
	cin>>c1;
	cout<<"Enter the second complex number:"<<endl;
	cin>>c2;
	cout<<"Enter the third complex number:"<<endl;
	cin>>c3;
	cout<<"Increment of C2"<<endl;
	cout<<c2++<<endl;
	cout<<c2<<endl;
	cout<<++c2<<endl;
	cout<<"Decrement of C2"<<endl;
	cout<<--c2<<endl;
	cout<<c2--<<endl;
	cout<<c2<<endl;
	cout<<"Multiplication\n";
	cout<<c1*c2*c3<<endl;
	cout<<"1.Mixed Expression:{(5 * 3 * c2 * c1) + c3 - c4}\n";
	cout<<5 * 3 * c2 * c1 + c3 - c4<<endl;
	cout<<"2.Mixed Expression:{5 * c1 * c2 / 2 * 4 }\n";
	cout<<5 * c1 * c2 / 2 * 4 <<endl;
	cout<<"3.Mixed Expression:{5 * (c1 * c2) / (2 * 4)}\n";
	cout<<5 * (c1 * c2) / (2 * 4)<<endl;
	cout<<"Increment 1:\n";
	cout<<c1++ + ++c2;
	return 0;
}
