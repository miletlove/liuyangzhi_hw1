/*
 * @Author: lyz 3068126392@qq.com
 * @Date: 2024-04-09 20:41:44
 * @LastEditors: lyz 3068126392@qq.com
 * @LastEditTime: 2024-04-10 16:55:47
 * @FilePath: \c++e:\Workspace\liuyangzhi_hw1\src\algebra.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "algebra.h"
#include <stdio.h>
#include <math.h>

Matrix create_matrix(int row, int col)
{
    Matrix m;
    m.rows = row;
    m.cols = col;
    return m;
}

Matrix add_matrix(Matrix a, Matrix b)
{
    Matrix create_matrix;
    create_matrix.rows = a.rows;
    create_matrix.cols = a.cols;
    int i = 0, j = 0;
    for (i = 0; i < a.rows; i++)
    {
        for (j = 0; j < a.cols; j++)
        {
            create_matrix.data[i][j] = a.data[i][j] + b.data[i][j];
        }
    } // ToDo finished
    return create_matrix;
}

Matrix sub_matrix(Matrix a, Matrix b)
{   if(a.rows==b.rows && b.cols==a.cols){
    Matrix create_matrix;
    create_matrix.rows = a.rows;
    create_matrix.cols = a.cols;
    int i = 0, j = 0;
    for (i = 0; i < a.rows; i++)
    {
        for (j = 0; j < a.cols; j++)
        {
            create_matrix.data[i][j] = a.data[i][j] - b.data[i][j];
        }
    }
    // ToDo finished
    return create_matrix;}else{
        printf("Error: Matrix a and b must have the same rows and cols");
    }
}

Matrix mul_matrix(Matrix a, Matrix b)
{
    if (a.cols != b.rows)
    {
        printf("Error:Matrix a's cols must be the same with b's rows");
    }
    else
    {
        Matrix create_matrix;
        create_matrix.rows = a.rows;
        create_matrix.cols = b.cols;
        int i, j;
        for (i = 0; i < a.rows; i++)
        {
            for (j = 0; j < b.cols; j++)
            {
                int k = 0;
                while (k < b.rows)
                {
                    create_matrix.data[i][j] += a.data[i][k] * b.data[k][j];
                    k++;
                }
            }
        }
        return create_matrix;
    }
    // ToDo finished
    
}

Matrix scale_matrix(Matrix a, double k)
{
    Matrix create_matrix;
    create_matrix.rows = a.rows;
    create_matrix.cols = a.cols;
    int i = 0, j = 0;
    for (i = 0; i < a.rows; i++)
    {
        for (j = 0; j < a.cols;j++)
        {
            create_matrix.data[i][j] = k * a.data[i][j];
        }
    }
    // ToDo finished
    return create_matrix;
}

Matrix transpose_matrix(Matrix a)
{
    // ToDo
    return create_matrix(0, 0);
}

double det_matrix(Matrix a)
{
    // ToDo
    return 0;
}

Matrix inv_matrix(Matrix a)
{
    // ToDo
    return create_matrix(0, 0);
}

int rank_matrix(Matrix a)
{
    // ToDo
    return 0;
}

double trace_matrix(Matrix a)
{
    // ToDo
    return 0;
}

void print_matrix(Matrix a)
{
    for (int i = 0; i < a.rows; i++)
    {
        for (int j = 0; j < a.cols; j++)
        {
            // 按行打印，每个元素占8个字符的宽度，小数点后保留2位，左对齐
            printf("%-8.2f", a.data[i][j]);
        }
        printf("\n");
    }
}