#include <string>
using namespace std;
template <typename T>
struct Matrix
{
	T** ptr;
	string name;
	int rows;
	int columns;
	Matrix(int r, int c)
	{
		this->rows = r;
		this->columns = c;
	}
	void addToList(string s, T** arr)
	{
		int r = this->rows;
		int c = this->columns;
		ptr = new T *[r];
		for (int i = 0; i < r; i++)
		{
			ptr[i] = new T[c];
		}
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				ptr[i][j] = arr[i][j];
			}
		}
		this->name = s;
	}
	void print()
	{
		int r = this->rows;
		int c = this->columns;
		cout << "Name of Matrix: " << this->name << " ";
		for (int i = 0; i < r; i++)
		{
			if (i == 0)
			{
				cout << "[";
			}
			for (int j = 0; j < c; j++)
			{
				if (i == r - 1 && j == c - 1)
				{
					cout << ptr[i][j] << "]";
					continue;
				}
				cout << ptr[i][j] << ",";
			}
		}
		cout << endl;
	}
	T** getValue()
	{
		return this->ptr;
	}
	int getR()
	{
		return this->rows;
	}
	int getC()
	{
		return this->columns;
	}
	void updateArray(T** arr, int r, int c)
	{
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				this->ptr[i][j] = arr[i][j];
			}
		}
	}
	string getName()
	{
		return this->name;
	}
};