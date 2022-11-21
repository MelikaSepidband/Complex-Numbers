#include <iostream>
#include <string>
#include <math.h>
using namespace std;
char x1,x2;
class complex{
	private:
	int real,img;
	public:
    void setNumber(int a,int b)
    {
    	real = a;
    	img = b;
	}
    int getReal()
	{
		return real;
	}
    int getImg()
    {
    	return img;
	}
	void operator ++ ()
	{
		real=++real;
	}
	void operator ++ (int)
	{
		real=real++;
	}
	void operator -- ()
	{
		real=--real;
	}
	void operator -- (int)
	{
		real=real--;
	}
	void operator +(complex c)
	{
		real=real+c.getReal();
		if(x2=='+'&& x1=='+')
    	{
		img=img+c.getImg();
		}
    	else if(x2=='+'&& x1=='-')
    	{
    	if(img<c.getImg())
		{
		img=abs(img-c.getImg());
		x2='-';
		}
		else if(img>=c.getImg())
		{
		img=abs(img-c.getImg());
		}
		}
		else if(x2=='-'&& x1=='+')
    	{
		if(img<=c.getImg())
		{
		img=abs(img-c.getImg());
		x2='+';
		}
		else if(img>c.getImg())
		{
		img=abs(img-c.getImg());
		}
		}
		else if(x2=='-'&& x1=='-')
    	{
		img=abs(img+c.getImg());
		}
	}
	void operator -(complex c)
	{
		real=real-c.getReal();
		if(x2=='+'&& x1=='+')
    	{
    		if(img<c.getImg())
    		{
    			img=abs(img-c.getImg());
    			x2='-';
			}
			else
			img=abs(img-c.getImg());
		}
    	else if(x2=='+'&& x1=='-')
    	{
		img=abs(img+c.getImg());
		}
		else if(x2=='-'&& x1=='+')
    	{
		img=abs(img+c.getImg());
		}
		else if(x2=='-'&& x1=='-')
    	{
			if(img<=c.getImg())
    		{
    			img=abs(img-c.getImg());
    			x2='+';
			}
			else
			img=abs(img-c.getImg());
		}
	}
    operator int() const
	{
		cout<<real<<endl;
		return real;
	}
	friend ostream & operator << (ostream& os,const complex& c);
	friend istream & operator >> (istream& is,complex& c);
};
ostream & operator << (ostream& os,const complex& c)
{
	if(x2=='+'||c.img==0)
	{
		cout<<c.real<<" + "<<c.img<<"i"<<endl;
	}
	else if(x2=='-'&&c.img!=0)
	{
		cout<<c.real<<" - "<<c.img<<"i"<<endl;
	}
	return os;
}
istream & operator >> (istream& is, complex& c)
{
	char y1;
	is>>c.real>>x1>>c.img>>y1;
	return is;
}
int main()
	{
		complex c1,c2;
		int a,b;
		char y2;
		cin>>a>>x2>>b>>y2;
		c1.setNumber(a,b);
		int n;
		cin>>n;
		string s;
		for(int i=0;i<n;i++)
		{
			cin>>s;
			if(s=="add")
			{
				cin>>c2;
				c1+c2;
			}
			if(s=="sub")
			{
				cin>>c2;
				c1-c2;
			}
			if(s=="int")
			{
				(int) c1;
			}
			if(s=="print")
			{
				cout<<c1;
			}
		}
	}
