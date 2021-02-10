/*
	Prepared By: Krish Rustagi
*/

#include <bits/stdc++.h> 
using namespace std;
typedef long long ll; 

class BigInteger
{
	string s;
	ll n;
	public:
		BigInteger(string str = "")
		{
			s = str;
			n = str.size();
		}
		BigInteger operator + (BigInteger const &b);
		BigInteger operator - (BigInteger const &b);
		void print()
		{
			cout << s << "\n";
		}
};

BigInteger BigInteger::operator + (BigInteger const &b)
{
	bool sign = 0;
	string s1, s2;
	s1 = s;
	s2 = b.s;
	
	if(s[0] == '-' and b.s[0] == '-')
	{
		sign = 1;
		s1 = s.substr(1, n - 1);
		s2 = b.s.substr(1, b.n - 1);
	}
	else if(s[0] == '-' and b.s[0] != '-')
	{
		s = s.substr(1, n - 1);
		BigInteger k = b;
		return (k - (*this));
	}
	else if(s[0] != '-' and b.s[0] == '-')
	{
		BigInteger k = b;
		k.s = b.s.substr(1, b.n - 1);
		return(*this - k);
	}


	BigInteger res("");
	ll car = 0;
	ll i = s1.size() - 1, j = s2.size() - 1;

	for(; i >= 0 and j >= 0; i--, j--)
	{
		ll temp1 = (ll)(s1[i] - '0');
		ll temp2 = (ll)(s2[j] - '0');
		ll temp3 = temp1 + temp2;
		if(temp3 + car < 10)
		{
			res.s += char(temp3 + car + '0');
			car = 0;
		}
		else
		{
			res.s += char((temp3 + car) % 10 + '0');
			car = 1;
		}
	}

	while(i >= 0)
	{
		ll temp3 = (ll)(s1[i] - '0');
		if(temp3 + car < 10)
		{
			res.s += char(temp3 + '0');
			car = 0;
		}
		else
		{
			res.s += char((temp3 + car) % 10 + '0');
			car = 1;
		}
		i--;
	}

	while(j >= 0)
	{
		ll temp3 = (ll)(s2[j] - '0');
		if(temp3 + car < 10)
		{
			res.s += char(temp3 + '0');
			car = 0;
		}
		else
		{
			res.s += char((temp3 + car) % 10 + '0');
			car = 1;
		}	
		j--;
	}

	if(car)
	{
		res.s += char(car + '0');
	}

	if(sign)
		res.s += '-';

	reverse(res.s.begin(), res.s.end());
	res.n = res.s.size();
	return res;
}

BigInteger BigInteger::operator - (BigInteger const &b)
{
	if(b.s[0] == '-')
	{
		BigInteger k = b;
		k.s = b.s.substr(1, b.n - 1);
		return ((*this) + k);
	}
	else if(s[0] == '-' and b.s[0] != '-')
	{
		BigInteger k = b;
		k.s = '-' + k.s;
		k.n++;
		return (*this + k);
	}

	ll n1, n2;
	ll sign = 0;
	string s1, s2, s3;
	s1 = s;
	s2 = b.s;
	n1 = s1.length();
	n2 = s2.length();

	if(n1 < n2)
	{
		sign=1;
		swap(s1, s2);
		swap(n1, n2);
	}
	else if(n1 == n2)
	{
		for(ll i = 0; i < n1; i++)
		{
		    if(s1[i] < s2[i])
		    {
		        sign = 1;
		        swap(s1, s2);
		        swap(n1, n2);
		        break;
		    }
		    else if(s1[i] > s2[i])
		    	break;
		}
	}

	ll bor = 0;
	while(n1 && n2)
	{
		ll a1, a2;
		a1 = s1[n1 - 1] - '0';
		a2 = s2[n2 - 1] - '0';

		ll sub = a1 - a2 - bor;

		if(sub < 0)
		{
			sub += 10;
			bor=1;
		}
		else
		{
			bor = 0;
		}

		s3 += (sub + '0');
		n1--;
		n2--;
	}

	while(n1)
	{
		ll sub;
		sub = (s1[n1 - 1]-'0') - bor;
		if(sub<0)
		{
			sub += 10;
			bor = 1;
		}
		else
		{
			bor = 0;
		}

		s3 += (sub + '0');
		n1--;
	}

	if(sign)
		s3 += '-';
	
	reverse(s3.begin(),s3.end());
	
	BigInteger res(s3);
	return res;
}

int main()
{
	string s1,s2;
	
	s1 = "789456123";
	s2 = "-321654987";
    BigInteger a(s1), b(s2);
    BigInteger c;
    
    cout << "First Number :\t\t";
    a.print();
    cout << "Second Number:\t\t";
    b.print();
    cout << endl;

    c = a + b;
    cout << "On Addition :\t\t";
    c.print();
    
    c = a - b;
    cout << "On Subtraction :\t";
    c.print();
    return 0;
}
