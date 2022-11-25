# include<iostream>
using namespace std;

//全局变量
int g_a = 10;
int g_b = 10;

//全局常量
const int c_g_a = 10;
const int c_g_b = 10;

void variable_demo(){
	//局部变量
	int a = 10;
	int b = 10;

	//打印地址
	cout << "局部变量a地址为： " << (int64_t)&a << endl;
	cout << "局部变量b地址为： " << (int64_t)&b << endl;

	cout << "全局变量g_a地址为： " <<  (int64_t)&g_a << endl;
	cout << "全局变量g_b地址为： " <<  (int64_t)&g_b << endl;

	//静态变量
	static int s_a = 10;
	static int s_b = 10;

	cout << "静态变量s_a地址为： " << (int64_t)&s_a << endl;
	cout << "静态变量s_b地址为： " << (int64_t)&s_b << endl;

	cout << "字符串常量地址为： " << (int64_t)&"hello world" << endl;
	cout << "字符串常量地址为： " << (int64_t)&"hello world1" << endl;

	cout << "全局常量c_g_a地址为： " << (int64_t)&c_g_a << endl;
	cout << "全局常量c_g_b地址为： " << (int64_t)&c_g_b << endl;

	const int c_l_a = 10;
	const int c_l_b = 10;
	cout << "局部常量c_l_a地址为： " << (int64_t)&c_l_a << endl;
	cout << "局部常量c_l_b地址为： " << (int64_t)&c_l_b << endl;


}

int* func()
{
	int* a = new int(10);
	return a;
}

void new_data1(){
	int *p = func();

	cout << *p << endl;
	cout << *p << endl;

	//利用delete释放堆区数据
	delete p;

	//cout << *p << endl; //报错，释放的空间不可访问

	
}

void new_data2(){
	int* arr = new int[10];

	for (int i = 0; i < 10; i++)
	{
		arr[i] = i + 100;
	}

	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;
	}
	//释放数组 delete 后加 []
	delete[] arr;
}

void cite_data1(){
	int a = 10;
	int &b = a;

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	b = 100;

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
}

void cite_data2(){
	int a = 10;
	int b = 20;
	//int &c; //错误，引用必须初始化
	int &c = a; //一旦初始化后，就不可以更改
	c = b; //这是赋值操作，不是更改引用

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
}

// int& test01() {
// 	int a = 10; //局部变量
// 	return a;
// }

//返回静态变量引用
int& test02() {
	static int a = 20;
	return a;
}

void return_func(){
	//不能返回局部变量的引用
	// int& ref = test01();
	// cout << "ref = " << ref << endl;
	// cout << "ref = " << ref << endl;

	//如果函数做左值，那么必须返回引用
	int& ref2 = test02();
	cout << "ref2 = " << ref2 << endl;
	cout << "ref2 = " << ref2 << endl;

	test02() = 1000;//函数调用返回左值

	cout << "after-ref2 = " << ref2 << endl;
	cout << "after-ref2 = " << ref2 << endl;
}

int main() {
	// variable_demo();
	// new_data1();
	// new_data2();
	return_func();
	system("pause");
	return 0;
}

