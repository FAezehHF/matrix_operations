#include "CMakeExercise.h"

using namespace std;

//define global vector list for save matrixes
vector<Matrix<int>> integerArrayList;
vector<Matrix<float>> floatArrayList;
vector<Matrix<char>> charArrayList;
vector<Matrix<string>> stringArrayList;


//define "==" overloading for matrix! because vs complier Confusion...
template <typename T> 
bool operator==(const Matrix<T>& m, const std::string& name) {
	return m.name == name; 
}

//check string is a number or not...
bool is_number(string& s)
{
	return !s.empty() && all_of(s.begin(), s.end(),isdigit);
}

//check string is a double number or not...
bool is_double(string& s)
{
	std::istringstream iss(s);
	float f;
	iss >> noskipws >> f; // noskipws considers leading whitespace invalid
						  // Check the entire string was consumed and if either failbit or badbit is set
	return iss.eof() && !iss.fail();
}

//reverse String!!
string reverseString(string& str)
{
	int n = str.length();
	for (int i = 0; i < n / 2; i++)
	{
		swap(str[i], str[n - i - 1]);
	}
	return str;
}

void changeArryaElement(string type, int index, string value, int desR, int desC)
{
	if (type == "int")
	{
		int r = integerArrayList.at(index).getR();
		int c = integerArrayList.at(index).getC();

		//check for enter row and col is a valid...
		if (desR >= r || desR < 0 || desC >= c || desC < 0)
		{
			cout << "index of row and col not valid..." << endl;
			return;
		}
		//check for enter value is a valid...
		if (is_number(value) == false)
		{
			cout << "value of row and col not valid..." << endl;
			return;
		}
		int** arr = integerArrayList.at(index).getValue();
		arr[desR][desC] = (int)round(stod(value));
		integerArrayList.at(index).updateArray(arr, r, c);
		cout << "updated successfully..." << endl;
		return;
	}
	if (type == "float")
	{
		int r = floatArrayList.at(index).getR();
		int c = floatArrayList.at(index).getC();

		if (desR >= r || desR < 0 || desC >= c || desC < 0)
		{
			cout << "index of row and col not valid..." << endl;
			return;
		}
		if (is_double(value) == false)
		{
			cout << "value of row and col not valid..." << endl;
			return;
		}
		float** arr = floatArrayList.at(index).getValue();
		arr[desR][desC] = stof(value);
		floatArrayList.at(index).updateArray(arr, r, c);
		cout << "updated successfully..." << endl;
		return;
	}
	if (type == "char")
	{
		int r = charArrayList.at(index).getR();
		int c = charArrayList.at(index).getC();

		if (desR >= r || desR < 0 || desC >= c || desC < 0)
		{
			cout << "index of row and col not valid..." << endl;
			return;
		}
		if (value.size() > 1)
		{
			cout << "value of row and col not valid..." << endl;
			return;
		}
		char** arr = charArrayList.at(index).getValue();
		arr[desR][desC] = value[0];
		charArrayList.at(index).updateArray(arr, r, c);
		cout << "updated successfully..." << endl;
		return;
	}
	if (type == "string")
	{
		int r = stringArrayList.at(index).getR();
		int c = stringArrayList.at(index).getC();

		if (desR >= r || desR < 0 || desC >= c || desC < 0)
		{
			cout << "index of row and col not valid..." << endl;
			return;
		}

		string** arr = stringArrayList.at(index).getValue();
		arr[desR][desC] = value;
		stringArrayList.at(index).updateArray(arr, r, c);
		cout << "updated successfully..." << endl;
		return;
	}
}
bool is_skew_symmetric(string type, int index)
{
	if (type == "int")
	{
		int** arr = integerArrayList.at(index).getValue();
		int r = integerArrayList.at(index).getR();
		int c = integerArrayList.at(index).getC();

		if (r != c)
		{
			
			return false;
		}

		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (arr[i][j] != (-1) * arr[j][i])
				{
					return false;
				}
			}
		}

		return true;
	}
	else if (type == "float")
	{
		float** arr = floatArrayList.at(index).getValue();
		int r = floatArrayList.at(index).getR();
		int c = floatArrayList.at(index).getC();

		if (r != c)
		{
			return false;
		}

		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{

				if (arr[i][j] != (-1) * arr[j][i])
				{
					return false;
				}
			}
		}

		return true;
	}
	else if (type == "char")
	{
		char** arr = charArrayList.at(index).getValue();
		int r = charArrayList.at(index).getR();
		int c = charArrayList.at(index).getC();

		if (r != c)
		{
			return false;
		}

		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{

				if (arr[i][j] != '-')
				{
					return false;
				}
			}
		}

		return true;
	}
	else if(type == "string")
	{
		string** arr = stringArrayList.at(index).getValue();
		int r = stringArrayList.at(index).getR();
		int c = stringArrayList.at(index).getC();

		if (r != c)
		{
			return false;
		}

		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{

				if (arr[i][j] != reverseString(arr[i][j]))
				{
					return false;
				}
			}
		}

		return true;
	}
}
bool is_normal_symmetric(string type, int index)
{
	if (type == "int")
	{
		int** arr = integerArrayList.at(index).getValue();
		int r = integerArrayList.at(index).getR();
		int c = integerArrayList.at(index).getC();

		if (r != c)
		{
			return false;
		}

		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (arr[i][j] != arr[j][i])
				{
					return false;
				}
			}
		}

		return true;
	}
	else if (type == "float")
	{
		float** arr = floatArrayList.at(index).getValue();
		int r = floatArrayList.at(index).getR();
		int c = floatArrayList.at(index).getC();

		if (r != c)
		{
			return false;
		}

		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{

				if (arr[i][j] != arr[j][i])
				{
					return false;
				}
			}
		}

		return true;
	}
	else if (type == "char")
	{
		char** arr = charArrayList.at(index).getValue();
		int r = charArrayList.at(index).getR();
		int c = charArrayList.at(index).getC();

		if (r != c)
		{
			return false;
		}

		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (arr[i][j] != arr[j][i])
				{
					return false;
				}
			}
		}

		return true;
	}
	else if(type == "string")
	{
		string** arr = stringArrayList.at(index).getValue();
		int r = stringArrayList.at(index).getR();
		int c = stringArrayList.at(index).getC();

		if (r != c)
		{
			return false;
		}

		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (arr[i][j] != arr[j][i])
				{
					return false;
				}
			}
		}

		return true;
	}
}
bool is_diagonal(string type, int index)
{
	if (type == "int")
	{

		int** arr = integerArrayList.at(index).getValue();
		int r = integerArrayList.at(index).getR();
		int c = integerArrayList.at(index).getC();

		if (r != c)
		{
			return false;
		}

		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (i == j)
				{
					continue;
				}
				if (arr[i][j] != 0)
				{
					return false;
				}
			}
		}

		return true;
	}
	else if (type == "float")
	{
		float** arr = floatArrayList.at(index).getValue();
		int r = floatArrayList.at(index).getR();
		int c = floatArrayList.at(index).getC();

		if (r != c)
		{
			return false;
		}

		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (i == j)
				{
					continue;
				}
				if (arr[i][j] != 0)
				{
					return false;
				}
			}
		}

		return true;
	}
	else if (type == "char")
	{
		char** arr = charArrayList.at(index).getValue();
		int r = charArrayList.at(index).getR();
		int c = charArrayList.at(index).getC();

		if (r != c)
		{
			return false;
		}

		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (i == j)
				{
					continue;
				}
				if (arr[i][j] != '0')
				{
					return false;
				}
			}
		}

		return true;
	}
	else if(type == "string")
	{
		string** arr = stringArrayList.at(index).getValue();
		int r = stringArrayList.at(index).getR();
		int c = stringArrayList.at(index).getC();

		if (r != c)
		{
			return false;
		}

		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (i == j)
				{
					continue;
				}
				if (arr[i][j] != "0")
				{
					return false;
				}
			}
		}

		return true;
	}
}
bool is_upper_triangular(string type, int index)
{
	if (type == "int")
	{
		int** arr = integerArrayList.at(index).getValue();
		int r = integerArrayList.at(index).getR();
		int c = integerArrayList.at(index).getC();
		if (r != c)
		{
			return false;
		}
		for (int i = 1; i < r; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (arr[i][j] != 0)
				{
					return false;
				}
			}
		}
		return true;
	}
	else if (type == "float")
	{
		float** arr = floatArrayList.at(index).getValue();
		int r = floatArrayList.at(index).getR();
		int c = floatArrayList.at(index).getC();
		if (r != c)
		{
			return false;
		}
		for (int i = 1; i < r; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (arr[i][j] != 0)
				{
					return false;
				}
			}
		}
		return true;
	}
	else if (type == "char")
	{
		char** arr = charArrayList.at(index).getValue();
		int r = charArrayList.at(index).getR();
		int c = charArrayList.at(index).getC();
		if (r != c)
		{
			return false;
		}
		for (int i = 1; i < r; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (arr[i][j] != '0')
				{
					return false;
				}
			}
		}
		return true;
	}
	else if(type == "string")
	{
		string** arr = stringArrayList.at(index).getValue();
		int r = stringArrayList.at(index).getR();
		int c = stringArrayList.at(index).getC();
		if (r != c)
		{
			return false;
		}
		for (int i = 1; i < r; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (arr[i][j] != "0")
				{
					return false;
				}
			}
		}
		return true;
	}
}
bool is_lower_triangular(string type, int index)
{
	if (type == "int")
	{
		int** arr = integerArrayList.at(index).getValue();
		int r = integerArrayList.at(index).getR();
		int c = integerArrayList.at(index).getC();
		if (r != c)
		{
			return false;
		}
		for (int i = 0; i < r; i++)
		{
			for (int j = i + 1; j < c; j++)
			{
				if (arr[i][j] != 0)
				{
					return false;
				}
			}
		}
		return true;
	}
	else if (type == "float")
	{
		float** arr = floatArrayList.at(index).getValue();
		int r = floatArrayList.at(index).getR();
		int c = floatArrayList.at(index).getC();
		if (r != c)
		{
			return false;
		}
		for (int i = 0; i < r; i++)
		{
			for (int j = i + 1; j < c; j++)
			{
				if (arr[i][j] != 0)
				{
					return false;
				}
			}
		}
		return true;
	}
	else if (type == "char")
	{
		char** arr = charArrayList.at(index).getValue();
		int r = charArrayList.at(index).getR();
		int c = charArrayList.at(index).getC();
		if (r != c)
		{
			return false;
		}
		for (int i = 0; i < r; i++)
		{
			for (int j = i + 1; j < c; j++)
			{
				if (arr[i][j] != '0')
				{
					return false;
				}
			}
		}
		return true;
	}
	else if(type == "string")
	{
		string** arr = stringArrayList.at(index).getValue();
		int r = stringArrayList.at(index).getR();
		int c = stringArrayList.at(index).getC();
		if (r != c)
		{
			return false;
		}
		for (int i = 0; i < r; i++)
		{
			for (int j = i + 1; j < c; j++)
			{
				if (arr[i][j] != "0")
				{
					return false;
				}
			}
		}
		return true;
	}
}
bool is_identity(string type, int index)
{
	if (type == "int")
	{
		if (is_diagonal(type, index))
		{
			int** arr = integerArrayList.at(index).getValue();
			int r = integerArrayList.at(index).getR();
			int c = integerArrayList.at(index).getC();

			for (int i = 0; i < r; i++)
			{
				for (int j = i; j < i + 1; j++)
				{
					if (arr[i][j] != 1)
					{
						return false;
					}
				}
			}
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (type == "float")
	{
		if (is_diagonal(type, index))
		{
			float** arr = floatArrayList.at(index).getValue();
			int r = floatArrayList.at(index).getR();
			int c = floatArrayList.at(index).getC();

			for (int i = 0; i < r; i++)
			{
				for (int j = i; j < i + 1; j++)
				{
					if (arr[i][j] != 1)
					{
						return false;
					}
				}
			}
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (type == "char")
	{
		if (is_diagonal(type, index))
		{
			char** arr = charArrayList.at(index).getValue();
			int r = charArrayList.at(index).getR();
			int c = charArrayList.at(index).getC();

			for (int i = 0; i < r; i++)
			{
				for (int j = i; j < i + 1; j++)
				{
					if (arr[i][j] != '1')
					{
						return false;
					}
				}
			}
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (type == "string")
	{
		if (is_diagonal(type, index))
		{
			string** arr = stringArrayList.at(index).getValue();
			int r = stringArrayList.at(index).getR();
			int c = stringArrayList.at(index).getC();

			for (int i = 0; i < r; i++)
			{
				for (int j = i; j < i + 1; j++)
				{
					if (arr[i][j] != "1")
					{
						return false;
					}
				}
			}
			return true;
		}
		else
		{
			return false;
		}
	}
}
bool is_nameExsit(string arrayName)
{
	if (find(integerArrayList.begin(), integerArrayList.end(), arrayName) != integerArrayList.end())
	{
		cout << "matrix name is alredy exist on integer lists" << endl;
		return true;
	}
	else if (find(floatArrayList.begin(), floatArrayList.end(), arrayName) != floatArrayList.end())
	{

		cout << "matrix name is alredy exist on float lists" << endl;
		return true;
	}
	else if (find(charArrayList.begin(), charArrayList.end(), arrayName) != charArrayList.end())
	{

		cout << "matrix name is alredy exist on char lists" << endl;
		return true;
	}
	else if (find(stringArrayList.begin(), stringArrayList.end(), arrayName) != stringArrayList.end())
	{
		cout << "matrix name is alredy exist on string lists" << endl;
		return true;
	}
	return false;
}
void fillArray(string arrayName, int r, int c, string values)
{

	bool floatFlag = true; // check for float array
	bool intFlag = true; // check for int array
	bool charFlag = true; // check for char array
	vector<string> data;

	if (is_nameExsit(arrayName))
	{
		return;
	}

	size_t k = 0;
	while (k < values.length() - 1) // breake value words into param array...
	{
		string d = "";
		if (values[k] != '[' && values[k] != ',' && values[k] != ']')
		{
			while (values[k] != ',' && k < values.length() - 1)
			{
				d += values[k];

				k++;
			}
			data.push_back(d);

		}
		k++;
	}
	if (data.size() != r * c)
	{
		cout << "number of array elements not correct... " << endl;
		return;
	}

	for (size_t i = 0; i < data.size(); i++)
	{
		if (is_number(data.at(i)) == false) // check if element is not int
		{
			intFlag = false;
		}
		if (intFlag == false && is_double(data.at(i)) == false)// check if element is not float
		{
			floatFlag = false;
		}
		if (intFlag == false && floatFlag == false && data.at(i).size() > 1) // check if element is not char
		{
			charFlag = false;
		}
	}

	if (intFlag)
	{
		k = 0;

		int** arr;
		arr = new int* [r];
		for (int i = 0; i < r; i++)
		{
			arr[i] = new int[c];
		}
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				arr[i][j] = stoi(data.at(k));
				k++;
			}
		}

		Matrix<int> temp(r, c);
		temp.addToList(arrayName, arr);
		integerArrayList.push_back(temp);
	}
	else if (floatFlag)
	{
		k = 0;
		float** arr;
		arr = new float* [r];
		for (int i = 0; i < r; i++)
		{
			arr[i] = new float[c];
		}
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				arr[i][j] = stof(data.at(k));
				k++;
			}
		}
		Matrix<float> temp(r, c);
		temp.addToList(arrayName, arr);
		floatArrayList.push_back(temp);
	}
	else
	{
		if (charFlag)
		{
			k = 0;
			char** arr;
			arr = new char* [r];
			for (int i = 0; i < r; i++)
			{
				arr[i] = new char[c];
			}
			for (int i = 0; i < r; i++)
			{
				for (int j = 0; j < c; j++)
				{
					arr[i][j] = data.at(k)[0];
					k++;
				}
			}
			Matrix<char> temp(r, c);
			temp.addToList(arrayName, arr);
			charArrayList.push_back(temp);
		}
		else
		{
			k = 0;
			string** arr;
			arr = new string * [r];
			for (int i = 0; i < r; i++)
			{
				arr[i] = new string[c];
			}
			for (int i = 0; i < r; i++)
			{
				for (int j = 0; j < c; j++)
				{
					arr[i][j] = data.at(k);
					k++;
				}
			}
			Matrix<string> temp(r, c);
			temp.addToList(arrayName, arr);
			stringArrayList.push_back(temp);
		}
	}
}
void showArray(string fullCommand)
{
	string word = "";
	string params[10];

	int i = 0;
	for (auto x : fullCommand)
	{
		if (x == ' ' || x == '\0')
		{
			params[i] = word;
			i++;
			word = "";
		}
		else
		{
			word += x;

		}
	}
	params[i] = word;
	if (i != 1) // command not valid
	{
		cout << "command not valid..." << endl;
		return;
	}
	string arrayname = params[1];
	if (find(integerArrayList.begin(), integerArrayList.end(), arrayname) != integerArrayList.end())
	{
		vector<Matrix<int>>::iterator it = std::find(integerArrayList.begin(), integerArrayList.end(), arrayname);
		int index = distance(integerArrayList.begin(), it);

		integerArrayList.at(index).print();
	}
	else if (find(floatArrayList.begin(), floatArrayList.end(), arrayname) != floatArrayList.end())
	{
		vector<Matrix<float>>::iterator it = std::find(floatArrayList.begin(), floatArrayList.end(), arrayname);
		int index = distance(floatArrayList.begin(), it);

		floatArrayList.at(index).print();
	}
	else if (find(charArrayList.begin(), charArrayList.end(), arrayname) != charArrayList.end())
	{
		vector<Matrix<char>>::iterator it = std::find(charArrayList.begin(), charArrayList.end(), arrayname);
		int index = distance(charArrayList.begin(), it);

		charArrayList.at(index).print();
	}
	else if (find(stringArrayList.begin(), stringArrayList.end(), arrayname) != stringArrayList.end())
	{
		vector<Matrix<string>>::iterator it = std::find(stringArrayList.begin(), stringArrayList.end(), arrayname);
		int index = distance(stringArrayList.begin(), it);

		stringArrayList.at(index).print();
	}
	else
	{
		cout << "Matrix not found..." << endl;
	}
}
void deleteArray(string fullCommand)
{
	string word = "";
	string params[10];

	int i = 0;
	for (auto x : fullCommand)
	{
		if (x == ' ' || x == '\0')
		{
			params[i] = word;
			i++;
			word = "";
		}
		else
		{
			word += x;

		}
	}
	params[i] = word;
	if (i != 1) // command not valid
	{
		cout << "command not valid..." << endl;
		return;
	}
	string arrayname = params[1];
	if (find(integerArrayList.begin(), integerArrayList.end(), arrayname) != integerArrayList.end())
	{
		vector<Matrix<int>>::iterator it = std::find(integerArrayList.begin(), integerArrayList.end(), arrayname);
		//int index = distance(integerArrayList.begin(), it);

		integerArrayList.erase(it);
	}
	else if (find(floatArrayList.begin(), floatArrayList.end(), arrayname) != floatArrayList.end())
	{
		vector<Matrix<float>>::iterator it = std::find(floatArrayList.begin(), floatArrayList.end(), arrayname);
		//int index = distance(floatArrayList.begin(), it);

		floatArrayList.erase(it);
	}
	else if (find(charArrayList.begin(), charArrayList.end(), arrayname) != charArrayList.end())
	{
		vector<Matrix<char>>::iterator it = std::find(charArrayList.begin(), charArrayList.end(), arrayname);
		//int index = distance(charArrayList.begin(), it);

		charArrayList.erase(it);
	}
	else if (find(stringArrayList.begin(), stringArrayList.end(), arrayname) != stringArrayList.end())
	{
		vector<Matrix<string>>::iterator it = std::find(stringArrayList.begin(), stringArrayList.end(), arrayname);
		//int index = distance(stringArrayList.begin(), it);

		stringArrayList.erase(it);
	}
	else
	{
		cout << "Matrix not found..." << endl;
	}
}
void checkArryaElement(string fullCommand)
{
	string word = "";
	string params[10];

	int i = 0;
	for (auto x : fullCommand)
	{
		if (x == ' ' || x == '\0')
		{
			params[i] = word;
			i++;
			word = "";
		}
		else
		{
			word += x;

		}
	}
	params[i] = word;
	if (i != 4) // command not valid
	{
		cout << "command not valid..." << endl;
		return;
	}
	if (is_number(params[2]) == false || is_number(params[3]) == false)
	{
		cout << "row and col not valid number..." << endl;
		return;
	}

	string arrayname = params[1];
	if (find(integerArrayList.begin(), integerArrayList.end(), arrayname) != integerArrayList.end())
	{
		vector<Matrix<int>>::iterator it = std::find(integerArrayList.begin(), integerArrayList.end(), arrayname);
		int index = distance(integerArrayList.begin(), it);
		changeArryaElement("int", index, params[4], stoi(params[2]), stoi(params[3]));
	}
	else if (find(floatArrayList.begin(), floatArrayList.end(), arrayname) != floatArrayList.end())
	{
		vector<Matrix<float>>::iterator it = std::find(floatArrayList.begin(), floatArrayList.end(), arrayname);
		int index = distance(floatArrayList.begin(), it);
		changeArryaElement("float", index, params[4], stoi(params[2]), stoi(params[3]));
	}
	else if (find(charArrayList.begin(), charArrayList.end(), arrayname) != charArrayList.end())
	{
		vector<Matrix<char>>::iterator it = std::find(charArrayList.begin(), charArrayList.end(), arrayname);
		int index = distance(charArrayList.begin(), it);
		changeArryaElement("char", index, params[4], stoi(params[2]), stoi(params[3]));
	}
	else if (find(stringArrayList.begin(), stringArrayList.end(), arrayname) != stringArrayList.end())
	{
		vector<Matrix<string>>::iterator it = std::find(stringArrayList.begin(), stringArrayList.end(), arrayname);
		int index = distance(stringArrayList.begin(), it);
		changeArryaElement("string", index, params[4], stoi(params[2]), stoi(params[3]));
	}
	else
	{
		cout << "Matrix not found..." << endl;
	}
}
void doInverse(string fullCommand)
{
	string word = "";
	string params[10];

	int i = 0;
	for (auto x : fullCommand)
	{
		if (x == ' ' || x == '\0')
		{
			params[i] = word;
			i++;
			word = "";
		}
		else
		{
			word += x;

		}
	}
	params[i] = word;
	if (i < 1 || i > 2) // command not valid
	{
		cout << "command not valid..." << endl;
		return;
	}
	string arrayname = params[1];
	if (find(integerArrayList.begin(), integerArrayList.end(), arrayname) != integerArrayList.end())
	{
		vector<Matrix<int>>::iterator it = std::find(integerArrayList.begin(), integerArrayList.end(), arrayname);
		int index = distance(integerArrayList.begin(), it);

		int** arr = integerArrayList.at(index).getValue();
		int r = integerArrayList.at(index).getR();
		int c = integerArrayList.at(index).getC();

		int** newArr;
		newArr = new int*[r];
		for (size_t j = 0; j < r; j++)
		{
			newArr[j] = new int[c];
		}
		for (int j = 0, m = r - 1; j < r; j++, m--)
		{
			for (int k = 0,  n = c - 1; k < c; k++, n--)
			{
				newArr[m][n] = arr[j][k];
			}
		}
		if (i == 1)
		{
			integerArrayList.at(index).updateArray(newArr, r, c);
		}
		else // commant has second name
		{
			if (is_nameExsit(params[2]))
			{
				cout << "matrix name is alredy exsit..." << endl;
				return;
			}
			Matrix<int> temp(r, c);
			temp.addToList(params[2], newArr);
			integerArrayList.push_back(temp);
		}
	}
	else if (find(floatArrayList.begin(), floatArrayList.end(), arrayname) != floatArrayList.end())
	{
		vector<Matrix<float>>::iterator it = std::find(floatArrayList.begin(), floatArrayList.end(), arrayname);
		int index = distance(floatArrayList.begin(), it);

		float** arr = floatArrayList.at(index).getValue();
		int r = floatArrayList.at(index).getR();
		int c = floatArrayList.at(index).getC();
		float** newArr;
		newArr = new float*[r];
		for (size_t j = 0; j < r; j++)
		{
			newArr[j] = new float[c];
		}
		for (int j = 0,  m = r - 1; j < r; j++, m--)
		{
			for (int k = 0,  n = c - 1; k < c; k++, n--)
			{
				newArr[m][n] = arr[j][k];
			}
		}
		if (i == 1)
		{
			floatArrayList.at(index).updateArray(newArr, r, c);
		}
		else // commant has second name
		{
			if (is_nameExsit(params[2]))
			{
				cout << "matrix name is alredy exsit..." << endl;
				return;
			}
			Matrix<float> temp(r, c);
			temp.addToList(params[2], newArr);
			floatArrayList.push_back(temp);
		}
	}
	else if (find(charArrayList.begin(), charArrayList.end(), arrayname) != charArrayList.end())
	{
		vector<Matrix<char>>::iterator it = std::find(charArrayList.begin(), charArrayList.end(), arrayname);
		int index = distance(charArrayList.begin(), it);

		char** arr = charArrayList.at(index).getValue();
		int r = charArrayList.at(index).getR();
		int c = charArrayList.at(index).getC();
		char** newArr;
		newArr = new char*[r];
		for (size_t j = 0; j < r; j++)
		{
			newArr[j] = new char[c];
		}
		for (int j = 0,  m = r - 1; j < r; j++, m--)
		{
			for (int k = 0,  n = c - 1; k < c; k++, n--)
			{
				newArr[m][n] = arr[j][k];
			}
		}
		if (i == 1)
		{
			charArrayList.at(index).updateArray(newArr, r, c);
		}
		else
		{
			if (is_nameExsit(params[2]))
			{
				cout << "matrix name is alredy exsit..." << endl;
				return;
			}
			Matrix<char> temp(r, c);
			temp.addToList(params[2], newArr);
			charArrayList.push_back(temp);
		}
	}
	else if (find(stringArrayList.begin(), stringArrayList.end(), arrayname) != stringArrayList.end())
	{
		vector<Matrix<string>>::iterator it = std::find(stringArrayList.begin(), stringArrayList.end(), arrayname);
		int index = distance(stringArrayList.begin(), it);

		string** arr = stringArrayList.at(index).getValue();
		int r = stringArrayList.at(index).getR();
		int c = stringArrayList.at(index).getC();
		string** newArr;
		newArr = new string*[r];
		for (size_t j = 0; j < r; j++)
		{
			newArr[j] = new string[c];
		}
		for (int j = 0,  m = r - 1; j < r; j++, m--)
		{
			for (int k = 0,  n = c - 1; k < c; k++, n--)
			{
				newArr[m][n] = arr[j][k];
			}
		}
		if (i == 1)
		{
			stringArrayList.at(index).updateArray(newArr, r, c);
		}
		else
		{
			if (is_nameExsit(params[2]))
			{
				cout << "matrix name is alredy exsit..." << endl;
				return;
			}
			Matrix<string> temp(r, c);
			temp.addToList(params[2], newArr);
			stringArrayList.push_back(temp);
		}

	}
	else
	{
		cout << "Matrix not found..." << endl;
	}
}
void check_symmetric(string fullCommand)
{
	string word = "";
	string params[10];

	int i = 0;
	for (auto x : fullCommand)
	{
		if (x == ' ' || x == '\0')
		{
			params[i] = word;
			i++;
			word = "";
		}
		else
		{
			word += x;

		}
	}
	params[i] = word;
	if (i != 1) // command not valid
	{
		cout << "command not valid..." << endl;
		return;
	}
	string arrayname = params[1];
	if (find(integerArrayList.begin(), integerArrayList.end(), arrayname) != integerArrayList.end())
	{
		vector<Matrix<int>>::iterator it = std::find(integerArrayList.begin(), integerArrayList.end(), arrayname);
		int index = distance(integerArrayList.begin(), it);

		if (is_normal_symmetric("int", index))
		{
			cout << "matrix is normal symmetric" << endl;
			
		}
		else
		{
			cout << "matrix isn't normal symmetric" << endl;
			
		}
		if (is_skew_symmetric("int", index))
		{
			cout << "matrix is skew symmetric" << endl;
			
		}
		else
		{
			cout << "matrix isn't skew symmetric" << endl;
			
		}
	}
	else if (find(floatArrayList.begin(), floatArrayList.end(), arrayname) != floatArrayList.end())
	{
		vector<Matrix<float>>::iterator it = std::find(floatArrayList.begin(), floatArrayList.end(), arrayname);
		int index = distance(floatArrayList.begin(), it);

		if (is_normal_symmetric("float", index))
		{
			cout << "matrix is normal symmetric" << endl;
			return;
		}
		else
		{
			cout << "matrix isn't normal symmetric" << endl;
			return;
		}
		if (is_skew_symmetric("float", index))
		{
			cout << "matrix is skew symmetric" << endl;
			return;
		}
		else
		{
			cout << "matrix isn't skew symmetric" << endl;
			return;
		}
	}
	else if (find(charArrayList.begin(), charArrayList.end(), arrayname) != charArrayList.end())
	{
		vector<Matrix<char>>::iterator it = std::find(charArrayList.begin(), charArrayList.end(), arrayname);
		int index = distance(charArrayList.begin(), it);

		if (is_normal_symmetric("char", index))
		{
			cout << "matrix is normal symmetric" << endl;
			return;
		}
		else
		{
			cout << "matrix isn't normal symmetric" << endl;
			return;
		}
		if (is_skew_symmetric("char", index))
		{
			cout << "matrix is skew symmetric" << endl;
			return;
		}
		else
		{
			cout << "matrix isn't  skew symmetric" << endl;
			return;
		}
	}
	else if (find(stringArrayList.begin(), stringArrayList.end(), arrayname) != stringArrayList.end())
	{
		vector<Matrix<string>>::iterator it = std::find(stringArrayList.begin(), stringArrayList.end(), arrayname);
		int index = distance(stringArrayList.begin(), it);

		if (is_normal_symmetric("string", index))
		{
			cout << "matrix is normal symmetric" << endl;
			return;
		}
		else
		{
			cout << "matrix isn't normal symmetric" << endl;
			return;
		}
		if (is_skew_symmetric("string", index))
		{
			cout << "matrix is skew symmetric" << endl;
			return;
		}
		else
		{
			cout << "matrix isn't  skew symmetric" << endl;
			return;
		}
	}
	else
	{
		cout << "Matrix not found..." << endl;
	}
}
void check_skew_symmetric(string fullCommand)
{
	string word = "";
	string params[10];

	int i = 0;
	for (auto x : fullCommand)
	{
		if (x == ' ' || x == '\0')
		{
			params[i] = word;
			i++;
			word = "";
		}
		else
		{
			word += x;

		}
	}
	params[i] = word;
	if (i != 1) // command not valid
	{
		cout << "command not valid..." << endl;
		return;
	}
	string arrayname = params[1];
	if (find(integerArrayList.begin(), integerArrayList.end(), arrayname) != integerArrayList.end())
	{
		vector<Matrix<int>>::iterator it = std::find(integerArrayList.begin(), integerArrayList.end(), arrayname);
		int index = distance(integerArrayList.begin(), it);

		if (is_skew_symmetric("int", index))
		{
			cout << "matrix is skew symmetric" << endl;
			return;
		}
		else
		{
			cout << "matrix isn't skew symmetric" << endl;
			return;
		}

	}
	else if (find(floatArrayList.begin(), floatArrayList.end(), arrayname) != floatArrayList.end())
	{
		vector<Matrix<float>>::iterator it = std::find(floatArrayList.begin(), floatArrayList.end(), arrayname);
		int index = distance(floatArrayList.begin(), it);

		if (is_skew_symmetric("float", index))
		{
			cout << "matrix is skew symmetric" << endl;
			return;
		}
		else
		{
			cout << "matrix isn't skew symmetric" << endl;
			return;
		}
	}
	else if (find(charArrayList.begin(), charArrayList.end(), arrayname) != charArrayList.end())
	{
		vector<Matrix<char>>::iterator it = std::find(charArrayList.begin(), charArrayList.end(), arrayname);
		int index = distance(charArrayList.begin(), it);

		if (is_skew_symmetric("char", index))
		{
			cout << "matrix is skew symmetric" << endl;
			return;
		}
		else
		{
			cout << "matrix isn't skew symmetric" << endl;
			return;
		}
	}
	else if (find(stringArrayList.begin(), stringArrayList.end(), arrayname) != stringArrayList.end())
	{
		vector<Matrix<string>>::iterator it = std::find(stringArrayList.begin(), stringArrayList.end(), arrayname);
		int index = distance(stringArrayList.begin(), it);

		if (is_skew_symmetric("string", index))
		{
			cout << "matrix is skew symmetric" << endl;
			return;
		}
		else
		{
			cout << "matrix isn't skew symmetric" << endl;
			return;
		}
	}
	else
	{
		cout << "Matrix not found..." << endl;
	}
}
void check_normal_symmetric(string fullCommand)
{
	string word = "";
	string params[10];

	int i = 0;
	for (auto x : fullCommand)
	{
		if (x == ' ' || x == '\0')
		{
			params[i] = word;
			i++;
			word = "";
		}
		else
		{
			word += x;

		}
	}
	params[i] = word;
	if (i != 1) // command not valid
	{
		cout << "command not valid..." << endl;
		return;
	}
	string arrayname = params[1];
	if (find(integerArrayList.begin(), integerArrayList.end(), arrayname) != integerArrayList.end())
	{
		vector<Matrix<int>>::iterator it = std::find(integerArrayList.begin(), integerArrayList.end(), arrayname);
		int index = distance(integerArrayList.begin(), it);

		if (is_normal_symmetric("int", index))
		{
			cout << "matrix is normal symmetric" << endl;
			return;
		}
		else
		{
			cout << "matrix isn't normal symmetric" << endl;
			return;
		}

	}
	else if (find(floatArrayList.begin(), floatArrayList.end(), arrayname) != floatArrayList.end())
	{
		vector<Matrix<float>>::iterator it = std::find(floatArrayList.begin(), floatArrayList.end(), arrayname);
		int index = distance(floatArrayList.begin(), it);

		if (is_normal_symmetric("float", index))
		{
			cout << "matrix is normal symmetric" << endl;
			return;
		}
		else
		{
			cout << "matrix isn't normal symmetric" << endl;
			return;
		}
	}
	else if (find(charArrayList.begin(), charArrayList.end(), arrayname) != charArrayList.end())
	{
		vector<Matrix<char>>::iterator it = std::find(charArrayList.begin(), charArrayList.end(), arrayname);
		int index = distance(charArrayList.begin(), it);

		if (is_normal_symmetric("char", index))
		{
			cout << "matrix is normal symmetric" << endl;
			return;
		}
		else
		{
			cout << "matrix isn't normal symmetric" << endl;
			return;
		}
	}
	else if (find(stringArrayList.begin(), stringArrayList.end(), arrayname) != stringArrayList.end())
	{
		vector<Matrix<string>>::iterator it = std::find(stringArrayList.begin(), stringArrayList.end(), arrayname);
		int index = distance(stringArrayList.begin(), it);

		if (is_normal_symmetric("string", index))
		{
			cout << "matrix is normal symmetric" << endl;
			return;
		}
		else
		{
			cout << "matrix isn't normal symmetric" << endl;
			return;
		}
	}
	else
	{
		cout << "Matrix not found..." << endl;
	}
}
void check_identity(string fullCommand)
{
	string word = "";
	string params[10];

	int i = 0;
	for (auto x : fullCommand)
	{
		if (x == ' ' || x == '\0')
		{
			params[i] = word;
			i++;
			word = "";
		}
		else
		{
			word += x;

		}
	}
	params[i] = word;
	if (i != 1) // command not valid
	{
		cout << "command not valid..." << endl;
		return;
	}
	string arrayname = params[1];
	if (find(integerArrayList.begin(), integerArrayList.end(), arrayname) != integerArrayList.end())
	{
		vector<Matrix<int>>::iterator it = std::find(integerArrayList.begin(), integerArrayList.end(), arrayname);
		int index = distance(integerArrayList.begin(), it);

		if (is_identity("int", index))
		{
			cout << "matrix is identity" << endl;
			return;
		}
		else
		{
			cout << "matrix isn't identity" << endl;
			return;
		}

	}
	else if (find(floatArrayList.begin(), floatArrayList.end(), arrayname) != floatArrayList.end())
	{
		vector<Matrix<float>>::iterator it = std::find(floatArrayList.begin(), floatArrayList.end(), arrayname);
		int index = distance(floatArrayList.begin(), it);

		if (is_identity("float", index))
		{
			cout << "matrix is identity" << endl;
			return;
		}
		else
		{
			cout << "matrix isn't identity" << endl;
			return;
		}
	}
	else if (find(charArrayList.begin(), charArrayList.end(), arrayname) != charArrayList.end())
	{
		vector<Matrix<char>>::iterator it = std::find(charArrayList.begin(), charArrayList.end(), arrayname);
		int index = distance(charArrayList.begin(), it);

		if (is_identity("char", index))
		{
			cout << "matrix is identity" << endl;
			return;
		}
		else
		{
			cout << "matrix isn't identity" << endl;
			return;
		}
	}
	else if (find(stringArrayList.begin(), stringArrayList.end(), arrayname) != stringArrayList.end())
	{
		vector<Matrix<string>>::iterator it = std::find(stringArrayList.begin(), stringArrayList.end(), arrayname);
		int index = distance(stringArrayList.begin(), it);

		if (is_identity("string", index))
		{
			cout << "matrix is identity" << endl;
			return;
		}
		else
		{
			cout << "matrix isn't identity" << endl;
			return;
		}
	}
}
void check_diagonal(string fullCommand)
{
	string word = "";
	string params[10];

	int i = 0;
	for (auto x : fullCommand)
	{
		if (x == ' ' || x == '\0')
		{
			params[i] = word;
			i++;
			word = "";
		}
		else
		{
			word += x;

		}
	}
	params[i] = word;
	if (i != 1) // command not valid
	{
		cout << "command not valid..." << endl;
		return;
	}
	string arrayname = params[1];
	if (find(integerArrayList.begin(), integerArrayList.end(), arrayname) != integerArrayList.end())
	{
		vector<Matrix<int>>::iterator it = find(integerArrayList.begin(), integerArrayList.end(), arrayname);
		int index = distance(integerArrayList.begin(), it);

		if (is_diagonal("int", index))
		{
			cout << "matrix is diagonal" << endl;
			return;
		}
		else
		{
			cout << "matrix isn't diagonal" << endl;
			return;
		}

	}
	else if (find(floatArrayList.begin(), floatArrayList.end(), arrayname) != floatArrayList.end())
	{
		vector<Matrix<float>>::iterator it = std::find(floatArrayList.begin(), floatArrayList.end(), arrayname);
		int index = distance(floatArrayList.begin(), it);

		if (is_diagonal("float", index))
		{
			cout << "matrix is diagonal" << endl;
			return;
		}
		else
		{
			cout << "matrix isn't diagonal" << endl;
			return;
		}
	}
	else if (find(charArrayList.begin(), charArrayList.end(), arrayname) != charArrayList.end())
	{
		vector<Matrix<char>>::iterator it = std::find(charArrayList.begin(), charArrayList.end(), arrayname);
		int index = distance(charArrayList.begin(), it);

		if (is_diagonal("char", index))
		{
			cout << "matrix is diagonal" << endl;
			return;
		}
		else
		{
			cout << "matrix isn't diagonal" << endl;
			return;
		}
	}
	else if (find(stringArrayList.begin(), stringArrayList.end(), arrayname) != stringArrayList.end())
	{
		vector<Matrix<string>>::iterator it = std::find(stringArrayList.begin(), stringArrayList.end(), arrayname);
		int index = distance(stringArrayList.begin(), it);

		if (is_diagonal("string", index))
		{
			cout << "matrix is diagonal" << endl;
			return;
		}
		else
		{
			cout << "matrix isn't diagonal" << endl;
			return;
		}
	}
	else
	{
		cout << "matrix not found..." << endl;
		return;
	}
}
void check_upper_triangular(string fullCommand)
{
	string word = "";
	string params[10];

	int i = 0;
	for (auto x : fullCommand)
	{
		if (x == ' ' || x == '\0')
		{
			params[i] = word;
			i++;
			word = "";
		}
		else
		{
			word += x;

		}
	}
	params[i] = word;
	if (i != 1) // command not valid
	{
		cout << "command not valid..." << endl;
		return;
	}
	string arrayname = params[1];
	if (find(integerArrayList.begin(), integerArrayList.end(), arrayname) != integerArrayList.end())
	{
		vector<Matrix<int>>::iterator it = std::find(integerArrayList.begin(), integerArrayList.end(), arrayname);
		int index = distance(integerArrayList.begin(), it);

		if (is_upper_triangular("int", index))
		{
			cout << "matrix is upper triangular" << endl;
			return;
		}
		else
		{
			cout << "matrix isn't upper triangular" << endl;
			return;
		}

	}
	else if (find(floatArrayList.begin(), floatArrayList.end(), arrayname) != floatArrayList.end())
	{
		vector<Matrix<float>>::iterator it = std::find(floatArrayList.begin(), floatArrayList.end(), arrayname);
		int index = distance(floatArrayList.begin(), it);

		if (is_upper_triangular("float", index))
		{
			cout << "matrix is upper triangular" << endl;
			return;
		}
		else
		{
			cout << "matrix isn't upper triangular" << endl;
			return;
		}
	}
	else if (find(charArrayList.begin(), charArrayList.end(), arrayname) != charArrayList.end())
	{
		vector<Matrix<char>>::iterator it = std::find(charArrayList.begin(), charArrayList.end(), arrayname);
		int index = distance(charArrayList.begin(), it);

		if (is_upper_triangular("char", index))
		{
			cout << "matrix is upper triangular" << endl;
			return;
		}
		else
		{
			cout << "matrix isn't upper triangular" << endl;
			return;
		}
	}
	else if (find(stringArrayList.begin(), stringArrayList.end(), arrayname) != stringArrayList.end())
	{
		vector<Matrix<string>>::iterator it = std::find(stringArrayList.begin(), stringArrayList.end(), arrayname);
		int index = distance(stringArrayList.begin(), it);

		if (is_upper_triangular("string", index))
		{
			cout << "matrix is upper triangular" << endl;
			return;
		}
		else
		{
			cout << "matrix isn't upper triangular" << endl;
			return;
		}
	}
}
void check_lower_triangular(string fullCommand)
{
	string word = "";
	string params[10];

	int i = 0;
	for (auto x : fullCommand)
	{
		if (x == ' ' || x == '\0')
		{
			params[i] = word;
			i++;
			word = "";
		}
		else
		{
			word += x;

		}
	}
	params[i] = word;
	if (i != 1) // command not valid
	{
		cout << "command not valid..." << endl;
		return;
	}
	string arrayname = params[1];
	if (find(integerArrayList.begin(), integerArrayList.end(), arrayname) != integerArrayList.end())
	{
		vector<Matrix<int>>::iterator it = std::find(integerArrayList.begin(), integerArrayList.end(), arrayname);
		int index = distance(integerArrayList.begin(), it);

		if (is_lower_triangular("int", index))
		{
			cout << "matrix is lower triangular" << endl;
			return;
		}
		else
		{
			cout << "matrix isn't lower triangular" << endl;
			return;
		}

	}
	else if (find(floatArrayList.begin(), floatArrayList.end(), arrayname) != floatArrayList.end())
	{
		vector<Matrix<float>>::iterator it = std::find(floatArrayList.begin(), floatArrayList.end(), arrayname);
		int index = distance(floatArrayList.begin(), it);

		if (is_lower_triangular("float", index))
		{
			cout << "matrix is lower triangular" << endl;
			return;
		}
		else
		{
			cout << "matrix isn't lower triangular" << endl;
			return;
		}
	}
	else if (find(charArrayList.begin(), charArrayList.end(), arrayname) != charArrayList.end())
	{
		vector<Matrix<char>>::iterator it = std::find(charArrayList.begin(), charArrayList.end(), arrayname);
		int index = distance(charArrayList.begin(), it);

		if (is_lower_triangular("char", index))
		{
			cout << "matrix is lower triangular" << endl;
			return;
		}
		else
		{
			cout << "matrix isn't lower triangular" << endl;
			return;
		}
	}
	else if (find(stringArrayList.begin(), stringArrayList.end(), arrayname) != stringArrayList.end())
	{
		vector<Matrix<string>>::iterator it = std::find(stringArrayList.begin(), stringArrayList.end(), arrayname);
		int index = distance(stringArrayList.begin(), it);

		if (is_lower_triangular("string", index))
		{
			cout << "matrix is lower triangular" << endl;
			return;
		}
		else
		{
			cout << "matrix isn't lower triangular" << endl;
			return;
		}
	}
}
void check_triangular(string fullCommand)
{
	string word = "";
	string params[10];

	int i = 0;
	for (auto x : fullCommand)
	{
		if (x == ' ' || x == '\0')
		{
			params[i] = word;
			i++;
			word = "";
		}
		else
		{
			word += x;

		}
	}
	params[i] = word;
	if (i != 1) // command not valid
	{
		cout << "command not valid..." << endl;
		return;
	}
	string arrayname = params[1];
	if (find(integerArrayList.begin(), integerArrayList.end(), arrayname) != integerArrayList.end())
	{
		vector<Matrix<int>>::iterator it = std::find(integerArrayList.begin(), integerArrayList.end(), arrayname);
		int index = distance(integerArrayList.begin(), it);

		if (is_upper_triangular("int", index))
		{
			cout << "matrix is upper triangular" << endl;
		}
		else
		{
			cout << "matrix isn't upper triangular" << endl;
		}
		if (is_lower_triangular("int", index))
		{
			cout << "matrix is lower triangular" << endl;
		}
		else
		{
			cout << "matrix isn't lower triangular" << endl;
		}
	}
	else if (find(floatArrayList.begin(), floatArrayList.end(), arrayname) != floatArrayList.end())
	{
		vector<Matrix<float>>::iterator it = std::find(floatArrayList.begin(), floatArrayList.end(), arrayname);
		int index = distance(floatArrayList.begin(), it);

		if (is_upper_triangular("float", index))
		{
			cout << "matrix is upper triangular" << endl;
		}
		else
		{
			cout << "matrix isn't upper triangular" << endl;
		}
		if (is_lower_triangular("float", index))
		{
			cout << "matrix is lower triangular" << endl;
			
		}
		else
		{
			cout << "matrix isn't lower triangular" << endl;
			
		}
	}
	else if (find(charArrayList.begin(), charArrayList.end(), arrayname) != charArrayList.end())
	{
		vector<Matrix<char>>::iterator it = std::find(charArrayList.begin(), charArrayList.end(), arrayname);
		int index = distance(charArrayList.begin(), it);

		if (is_upper_triangular("char", index))
		{
			cout << "matrix is upper triangular" << endl;
			
		}
		else
		{
			cout << "matrix isn't upper triangular" << endl;
			
		}
		if (is_lower_triangular("char", index))
		{
			cout << "matrix is lower triangular" << endl;
			
		}
		else
		{
			cout << "matrix isn't lower triangular" << endl;
			
		}
	}
	else if (find(stringArrayList.begin(), stringArrayList.end(), arrayname) != stringArrayList.end())
	{
		vector<Matrix<string>>::iterator it = std::find(stringArrayList.begin(), stringArrayList.end(), arrayname);
		int index = distance(stringArrayList.begin(), it);

		if (is_upper_triangular("string", index))
		{
			cout << "matrix is upper triangular" << endl;
			
		}
		else
		{
			cout << "matrix isn't upper triangular" << endl;
			
		}
		if (is_lower_triangular("string", index))
		{
			cout << "matrix is lower triangular" << endl;
			
		}
		else
		{
			cout << "matrix isn't lower triangular" << endl;
			
		}
	}
}
string commandSeparator(string s)
{
	for (int i = s.size() - 1; i >= 0; i--)
	{
		if (s[i] == ' ' && s[i] == s[i - 1])
		{
			s.erase(s.begin() + i);
		}
	}
	s[s.size()] = ' ';
	for (auto& c : s)
	{
		c = tolower(c);
	}
	return s;
}
void addMatrix(string fullCommand)
{
	string word = "";
	string params[10];

	int i = 0;
	for (auto x : fullCommand)//Separates the words of the string. This code is equivalent to strtok() function.
	{
		if (x == ' ' || x == '\0')
		{
			params[i] = word;
			i++;
			word = "";
		}
		else
		{
			word += x;

		}
	}
	params[i] = word;

	if (i != 5 && i != 4)//if command not valid
	{
		cout << "command not valid..." << endl;
		return;
	}
	if (!is_number(params[3]))//if first row not number
	{
		cout << "row isn't valid..." << endl;
		return;
	}
	if (i == 5 && !is_number(params[4]))//if second col not number
	{
		cout << "column isn't valid..." << endl;
		return;
	}

	if (i == 5) // array has column
	{
		fillArray(params[2], stoi(params[3]), stoi(params[4]), params[5]);
	}
	else
	{
		fillArray(params[2], stoi(params[3]), stoi(params[3]), params[4]);
	}
}
void help()
{
	cout << "add matrix\n" << "Example:add matrix Matrixname row column"
		<< "\nExample:add matrix Matrixname row \n"
		<< "is_diagonal\n" << "Example:is_diagonal Matrixname\n"
		<< "is_upper_triangular\n" << "Example:is_upper_triangular Matrixname\n"
		<< "is_lower_triangular\n" << "Example:is_lower_triangular Matrixname\n"
		<< "is_triangular\n" << "Example:is_triangular Matrixname\n"
		<< "is_identity\n" << "Example: is_identity Matrixname\n"
		<< "is_normal_symmetric\n" << "Example:is_normal_symmetric Matrixname\n"
		<< "is_skew_symmetric\n" << "Example:is_skew_symmetric Matrixname\n"
		<< "is_symmetric\n" << "Example:is_symmetric Matrixname\n"
		<< "inverse\n" << "Example:inverse Matrixname"
		<< "Example:inverse Matrixname newMatrxname\n"
		<< "show \n" << "Example:show Matrixname\n"
		<< "delete\n" << "Example:delete Matrixname\n"
		<< "change\n" << "Example:change Matrixname row column Newvalue"
		<< "\tchange Matrixname row Newvalue"
		<< "exit\n"
		<< "help\n";
}
void runCommands(string mainCommand, string fullCommand)
{

	if (mainCommand == "add")
	{
		addMatrix(fullCommand);
		return;
	}
	if (mainCommand == "is_diagonal")
	{
		check_diagonal(fullCommand);
		return;
	}
	if (mainCommand == "is_upper_triangular")
	{
		check_upper_triangular(fullCommand);
		return;
	}
	if (mainCommand == "is_lower_triangular")
	{
		check_lower_triangular(fullCommand);
		return;
	}
	if (mainCommand == "is_triangular")
	{
		check_triangular(fullCommand);
		return;
	}
	if (mainCommand == "is_identity")
	{
		check_identity(fullCommand);
		return;
	}
	if (mainCommand == "is_normal_symmetric")
	{
		check_normal_symmetric(fullCommand);
		return;
	}
	if (mainCommand == "is_skew_symmetric")
	{
		check_skew_symmetric(fullCommand);
		return;
	}
	if (mainCommand == "is_symmetric")
	{
		check_symmetric(fullCommand);
		return;
	}
	if (mainCommand == "inverse")
	{
		doInverse(fullCommand);
		return;
	}
	if (mainCommand == "show")
	{
		showArray(fullCommand);
		return;
	}
	if (mainCommand == "delete")
	{
		deleteArray(fullCommand);
		return;
	}
	if (mainCommand == "change")
	{
		checkArryaElement(fullCommand);
		return;
	}
	if (mainCommand == "help")
	{
		help();
		return;
	}
}
bool Menu()
{
	string s;
	cout << "Enter Your Commands:" << endl;
	getline(cin, s);
	s = commandSeparator(s);
	string mainCommand = s.substr(0, s.find(" "));//This code saves the first word of the comment as the main word
	if (mainCommand == "exit")
	{
		return false;
	}
	runCommands(mainCommand, s);
	return true;
}