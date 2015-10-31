#include <iostream>
using namespace std;
class String {
	public:
		String(const char* str =NULL);
		String(const String &another); //拷贝构造
		~String();
		String &operator=(const String& another);
	private:
		char* m_data;
};

String::String(const char* str) {
	if(str==NULL) {
		m_data = new char[1];
		m_data[0] = '\0';
	} else {
		m_data = new char[strlen(str)+1];
		strcpy(m_data,str);
	}
}

String::String(const String& another) {
	m_data = new char[strlen(another.m_data)+1];
	strcpy(m_data,another.m_data);
}

String::String& operator = (const &another) {
	if(this==another) {
		return *this;
	}
	////赋值说明之前已经有值，
	//当把指针指向另一个地方时，需要把之前的那个数删除，
	//否则指针改变后,之前那个数所占用的空间没有人访问，也没删除
	//那么就内存泄露了!
	delete []m_data; 
	m_data = new char[strlen(another.m_data)+1];
	strcpy(m_data,another.m_data);
	return *this;
}
int main() {
	
}