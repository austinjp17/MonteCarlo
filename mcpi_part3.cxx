#include <iostream>
#include <array>
#include <chrono>

using namespace std;
using namespace std::chrono;

#define N_POINTS 100
#define M_DIM 2
#define TYPE double

#define KB 1024
#define MB KB*KB
#define GB MB*KB

void runPI(int rows, int cols)
{
	TYPE **arr = new TYPE *[rows];
	TYPE num_inside = 0;

	// PART 2
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new TYPE[cols];
		for (int j = 0; j < cols; j++)
		{
			TYPE randFloat = static_cast<TYPE>(rand()) / static_cast<TYPE>(RAND_MAX);
			arr[i][j] = randFloat;
		}
	}

	//timer begin
	auto start = high_resolution_clock::now();

	// squareLoop
	// PART 3
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = arr[i][j] * arr[i][j];
		}
	}

	// SumRows
	// PART 4
	TYPE summed[rows];
	for (int i = 0; i < rows; i++)
	{
		TYPE rowSum = 0;
		for (int j = 0; j < cols; j++)
		{
			rowSum += arr[i][j];
		}
		summed[i] = rowSum;
	}

	// Count if within unit circle
	// PART 5
	for (int i = 0; i < rows; i++)
	{
		if (summed[i] <= 1.0f)
		{
			num_inside += 1;
		}
	}

	TYPE pi = 4.0 * (TYPE(num_inside) / TYPE(rows));

	auto stop = high_resolution_clock::now();
	auto duration_ms = duration_cast<milliseconds>(stop - start);
	auto duration_us = duration_cast<microseconds>(stop - start).count();
	auto duration_ns = duration_cast<nanoseconds>(stop - start).count();

	auto mem_usage = (N_POINTS * M_DIM * sizeof(TYPE)) + (N_POINTS * sizeof(TYPE));

	cout << "Precision                      =  " << sizeof(TYPE) << endl;
	cout << "Sample Size                    =  " << N_POINTS << endl;
	cout << "Total memory footprint (Bytes) =  " << mem_usage << endl;
	cout << "Total memory footprint (MB)    =  " << float(mem_usage)/(MB) << endl;
	cout << "Total memory footprint (GB)    =  " << float(mem_usage)/(GB) << endl;
	cout << "\nPi = " << pi << endl;
	cout << "Timing = " << double(duration_ns)/1000000000.0 << " (seconds)" << endl;
}

int main()
{
	runPI(N_POINTS, M_DIM);
	return 0;
}
