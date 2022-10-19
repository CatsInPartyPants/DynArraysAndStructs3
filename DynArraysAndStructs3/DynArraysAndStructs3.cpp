#include <iostream>

void moveRow(int** arr, int M, int N, int count);

void moveColomn(int** arr, int M, int N, int count);

int main()
{
    int** arr3 = new int* [5];
    for (int i = 0; i < 5; i++)
    {
        arr3[i] = new int[5];
    }
    srand(time(NULL));

    // before 
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            arr3[i][j] = 1 + rand() % (50 + 1);
            std::cout << arr3[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    //after
    moveRow(arr3, 5, 5, 2);
    moveColomn(arr3, 5, 5, 2);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            std::cout << arr3[i][j] << " ";
        }
        std::cout << std::endl;
    }

    //delete dynamic array

    for (int i = 0; i < 5; i++)
    {
        delete[] arr3[i];
    }
    delete[] arr3;
}

void moveRow(int** arr, int M, int N, int count)
{
    
    for (int i = 0; i < M; i++)
    {
        for (int k = 0; k < count; k++)
        {
            int temp;
            temp = arr[i][0];
            for (int j = 0; j < N; j++)
            {
                arr[i][j] = arr[i][j + 1];
            }
            arr[i][N - 1] = temp;
        } 
    }
}

void moveColomn(int** arr, int M, int N, int count)
{
    for (int j = 0; j < N; j++)
    {
        for (int k = 0; k < count; k++)
        {
            int temp = 0;
            temp = arr[0][j];
            for (int i = 0; i < M - 1; i++)
            {
                arr[i][j] = arr[i + 1][j];
            }
            arr[M - 1][j] = temp;
        }
        
    }
}