#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
stack<char> sta;
int judge(string s);
int main()	{
	string s;
	cin >> s;
	if (judge(s))	cout <<"YES"<<endl;
	else	cout <<"NO"<<endl;
	return 0;
}

int judge(string s)	{
	char* ps=(char*)s.c_str();
	int i=0;
	while (ps[i++]!='\0')	{
		switch(ps[i])	{
			case '(':case '[':case '{': sta.push(ps[i]);break;
			case ')':	{
				if (!sta.empty()&&sta.top()=='(')	sta.pop();
				else return 0;
				break;
			}
			case ']':	{
				if (!sta.empty()&&sta.top()=='[')	sta.pop();
				else return 0;
				break;
			}
			case '}':	{
				if (!sta.empty()&&sta.top()=='{')	sta.pop();
				else return 0;
				break;
			}
			default:;
		}
	}
	return sta.empty();
}
