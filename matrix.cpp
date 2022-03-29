#include <iostream>
#include <vector>
#include <iomanip>

std::vector<std::vector<int>>
	matrix_mult(std::vector<std::vector<int>> left, std::vector<std::vector<int>> right);
	
std::vector<std::vector<int>>
	skalar(int c, std::vector<std::vector<int>> right);

void printer (std::vector<std::vector<int>> matrix);

int main ()
{
	const std::vector<std::vector<int>> m1 = {
		{ 1, 2, 3, 4, 5 },
		{ 6, 7, 8, 9, 10 }
	};
	const std::vector<std::vector<int>> m2 = {
		{ 1, 2 },
		{ 3, 4 },
		{ 5, 6 },
		{ 7, 8 },
		{ 9, 10 }
	};
	const std::vector<std::vector<int>> m3 = {
		{ 1, 2, 3 },
		{ 4, 5, 6 },
		{ 7, 8, 9 },
		{ 10, 11, 12 },
		{ 13, 14, 15 }
	};
	
	std::vector<std::vector<int>> r1 = skalar(3, m1);
	std::vector<std::vector<int>> r2 = matrix_mult(m1, m2);
	std::vector<std::vector<int>> r3 = matrix_mult(m2, m1);
	std::vector<std::vector<int>> r4 = matrix_mult(m1, m3);
	printer(r1);
	std::cout << '\n';
	printer(r2);
	std::cout << '\n';
	printer(r3);
	std::cout << '\n';
	printer(r4);
	return 0;
}

std::vector<std::vector<int>>
	skalar(int c, std::vector<std::vector<int>> right)
{
	std::vector<std::vector<int>> product = right;	//itt direkt használtam ezt a megoldást, mivel ez egy
							//egyszerűbb művelet, mint a másik, és akkor már a
	for (size_t i = 0; i < right.size(); ++i)	//size_t-t is használom, csak hogy benne legyen
	{
		for (size_t j = 0; j < right[i].size(); ++j)
		{
			product[i][j] = right [i][j] * c;
		}
	}
	return product;
}

std::vector<std::vector<int>>
	matrix_mult(std::vector<std::vector<int>> left, std::vector<std::vector<int>> right)
{
	int left_col_dim = left.size();
	int left_row_dim = left[0].size();
	int right_row_dim = right[0].size();
	std::vector<std::vector<int>> product (left_col_dim);

	for (int i = 0; i < left_col_dim; ++i)
	{
		product[i] = std::vector<int>(right_row_dim);
		for (int j = 0; j < right_row_dim; ++j)
		{
			for (int k = 0; k < left_row_dim; ++k)
			{			
				product[i][j] += left[i][k] * right[k][j];
			
			}
		}
	}
	return product;
}

void printer (std::vector<std::vector<int>> matrix)
{
	int col_dim = matrix.size();
	int row_dim = matrix[0].size();

	for ( int i = 0; i < col_dim; ++i)
	{
		for ( int j = 0; j < row_dim; ++j)
		{
			std::cout << std::setw(6) << matrix[i][j];
		}
		std::cout << '\n';
	}
}





