#include <iostream>
#include <climits>
using namespace std;
const int INF = 2000000;
const int SIZE = 7;
void fill_peaks_matrix(int matrix[][SIZE], int rows);
void show_matrix(int matrix[][SIZE], int rows);
void route(int peaks[][SIZE], int start, int end);

int main()
{

	int distances[SIZE][SIZE] = {
		{ 0, 5, 1, INF, INF, INF, INF },
		{ 5, 0, INF, 3, INF, 6, INF },
		{ 1, INF, 0, 2, 4, INF, INF },
		{ INF, 3, 2, 0, 1, INF, INF },
		{ INF, INF, 4, 1, 0, 4, 3 },
		{ INF, 6, INF, INF, 4, 0 ,3 },
		{ INF, INF, INF, INF, 3, 3, 0 }
	};

	int points[SIZE][SIZE];

	fill_peaks_matrix(points, SIZE);
	show_matrix(distances, SIZE);

	for (int k = 0; k < SIZE; ++k)
		for (int i = 0; i < SIZE; ++i)
			for (int j = 0; j < SIZE; ++j)
			{
				if (distances[i][k] < INF && distances[k][j] < INF)
				{

					if ((distances[i][k] + distances[k][j]) < distances[i][j])
					{
						distances[i][j] = distances[i][k] + distances[k][j];
						points[i][j] = k + 1;
					}
				
				}

			}
	
	show_matrix(distances, SIZE);
	cout << "0 mean that shorter way through another peaks is not available" << endl
		<< "(i-j is shortest way between two peaks)" << endl;
	show_matrix(points, SIZE);

	cout << "Enter 2 points to route:";
	int point1;
	int point2;
	cin >> point1;
	cin >> point2;
	cout << endl;
	cout << point1;
	route(points, point1, point2);
	cout << "-" << point2;
}

// виведенння матриці
void show_matrix(int matrix[][SIZE], int rows)
{
	using namespace std;
	cout << "  ";
	for (int i = 0; i < SIZE; i++)
		cout << i + 1 << " ";
	cout << endl;
	for (int i = 0; i < rows; i++)
	{
		cout << i + 1 << " ";
		for (int j = 0; j < SIZE; j++)
		{
			if (matrix[i][j] != INF)
				cout << matrix[i][j] << " ";
			else
				cout << "I ";
		}
		cout << endl;
	}
	cout << endl;
}
// Заповнення матриці вершин нулями
void fill_peaks_matrix(int matrix[][SIZE], int rows)
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < rows; j++)
			matrix[i][j] = 0;
}
// Знаходження шляху за допомогою рекурсії
void route(int peaks[][7], int start, int end)
{
	

	if (peaks[start - 1][end - 1] > 0)
	{
		
		if (end > start)
		{
			route(peaks, start, peaks[start - 1][end - 1]);
			cout << "-" << peaks[start - 1][end - 1];
		}
		else if (start > end)
		{
			cout << "-" << peaks[start - 1][end - 1];
			route(peaks, peaks[start - 1][end - 1], end);
			
		}

		
	}
	
	
	
	



	
}
