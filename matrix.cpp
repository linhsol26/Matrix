#include <stdio.h>

int fillMatrix(int arr[100][100], int n, int m) {
    int num = 1, direct = 0, row = m - 1, col = n - 1;
    while (num <= m * n) {
        if (direct == 0) {
            for (int i = 0; i <= col; i++) { // left to right (up)
            arr[direct][i] = num++;
            }
        } 
        else {
            for (int i = 1; i <= col; i++) { // left to right (up)
            arr[direct][i] = num++;
            }
        }
        
        for (int i = direct + 1; i <= row; i++) { //top to down (right)
            arr[i][col] = num++;
        }
        for (int i = col - 1; i >= direct && num < m * n; i--) { //right to left (bottom)
            arr[row][i] = num++;
        }
        for (int i = row - 1; i > direct && num < m * n; i--) { //bottom to top (left)
            arr[i][direct] = num++;
        }
        direct++;
        row--;
        col--;
        //10???????
    }
}

void printMatrix (int arr[100][100], int n, int m) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d \t", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int arr[100][100];
    fillMatrix(arr, n, m);
    printMatrix(arr, n, m);
}