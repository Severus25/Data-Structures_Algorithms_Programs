#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
using namespace std;

// FinalCost class stores the final label and cost of the optimal solution
class FinalCost {
public:
	string label = "";
	int cost = INT_MAX;
};

class MatrixMultiplyCost {
public:
	// Recursive function that finds the optimal cost and
	// label

	void optimalCost(int** matrices, string* labels,
					int prevCost, FinalCost& finalCost,
					int len)
	{
		// Base case: If there are no or only one matrix,
		// the cost is 0 and there is no need for a label
		if (len < 2) {
			finalCost.cost = 0;
			return;
		}
	
		// Base case: If there are only two matrices, the
		// cost is the product of their dimensions and the
		// label is the concatenation of their labels
		else if (len == 2) {
			int cost = prevCost
					+ (matrices[0][0] * matrices[0][1]
						* matrices[1][1]);
			if (cost < finalCost.cost) {
				finalCost.cost = cost;
				finalCost.label
					= "(" + labels[0] + labels[1] + ")";
			}
			return;
		}
	
		// Iterate through all possible matrix combinations
		for (int i = 0; i < len - 1; i++) {
			int j;
		
			// Create new matrices and labels after merging
			// two matrices
			int** newMatrix = new int*[len - 1];
			string* newLabels = new string[len - 1];
			int subIndex = 0;
		
			// Calculate the cost of merging matrices[i] and
			// matrices[i+1]
			int cost = (matrices[i][0] * matrices[i][1]
						* matrices[i + 1][1]);
		
			// Copy over the matrices and labels before the
			// merge
			for (j = 0; j < i; j++) {
				newMatrix[subIndex] = matrices[j];
				newLabels[subIndex++] = labels[j];
			}
		
			// Add the merged matrix and label
			newMatrix[subIndex] = new int[2];
			newMatrix[subIndex][0] = matrices[i][0];
			newMatrix[subIndex][1] = matrices[i + 1][1];
			newLabels[subIndex++]
				= "(" + labels[i] + labels[i + 1] + ")";
		
			// Copy over the matrices and labels after the
			// merge
			for (j = i + 2; j < len; j++) {
				newMatrix[subIndex] = matrices[j];
				newLabels[subIndex++] = labels[j];
			}
		
			// Recursively call the function with the new
			// matrices and labels
			optimalCost(newMatrix, newLabels,
						prevCost + cost, finalCost,
						len - 1);
		}
	}
	
	FinalCost findOptionalCost(int* arr, int len)
	{
	
		// Create matrices and labels from the input array
		int** matrices = new int*[len - 1];
		string* labels = new string[len- 1];
		for (int i = 0; i < len - 1; i++) {
			matrices[i] = new int[2];
			matrices[i][0] = arr[i];
			matrices[i][1] = arr[i + 1];
			labels[i] = char(
				65 + i); // Assign labels as A, B, C, etc.
		}
		FinalCost finalCost;
	
		// Call the recursive function to find the optimal
		// cost and label
		optimalCost(matrices, labels, 0, finalCost,
					len - 1);
		return finalCost;
	}
};
void printMatrix(int ** matrices, int len) {
		cout << "matrices = " << endl << "[";
		for (int i = 0; i < len; i++) {
			cout << "[" << matrices[i][0] << " " << matrices[i][1] << "]" << " ";
		}
		cout << "]" << endl;
	}

int main() {
	MatrixMultiplyCost calc;

	int arr[] = {40, 20, 30, 10, 30};
	int len = sizeof(arr) / sizeof(arr[0]);
	int **matrices = new int*[len - 1];
	string *labels = new string[len - 1];

	for (int i = 0; i < len - 1; i++) {
		matrices[i] = new int[2];
		matrices[i][0] = arr[i];
		matrices[i][1] = arr[i + 1];
		labels[i] = char(65 + i);
	}

	printMatrix(matrices, len-1);

	FinalCost cost = calc.findOptionalCost(arr, len);
	cout << "Final labels: \n" << cost.label << endl;
	cout << "Final Cost:\n" << cost.cost << endl;

	return 0;
}
