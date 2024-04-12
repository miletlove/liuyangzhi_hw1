/*
 * @Author: lyz 3068126392@qq.com
 * @Date: 2024-04-09 20:41:44
 * @LastEditors: lyz 3068126392@qq.com
 * @LastEditTime: 2024-04-12 22:50:30
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
    Matrix c = create_matrix(a.rows, a.cols);
    if (a.rows == b.rows && a.cols == b.cols)
    {
        int i = 0, j = 0;
        for (i = 0; i < a.rows; i++)
        {
            for (j = 0; j < a.cols; j++)
            {
                c.data[i][j] = a.data[i][j] + b.data[i][j];
            }
        } // ToDo finished
        return c;
    }
    else
    {
        printf("Error: Matrix a and b must have the same rows and cols.\n");
        return create_matrix(0, 0);
    }
}

Matrix sub_matrix(Matrix a, Matrix b)
{
    Matrix c = create_matrix(a.rows, a.cols);
    if (a.rows == b.rows && a.cols == b.cols)
    {
        int i = 0, j = 0;
        for (i = 0; i < a.rows; i++)
        {
            for (j = 0; j < a.cols; j++)
            {
                c.data[i][j] = a.data[i][j] - b.data[i][j];
            }
        } // ToDo finished
        return c;
    }
    else
    {
        printf("Error: Matrix a and b must have the same rows and cols.\n");
        return create_matrix(0, 0);
    }
}

Matrix mul_matrix(Matrix a, Matrix b)
{
    Matrix c = create_matrix(a.rows, b.cols);
    if (a.cols != b.rows)
    {
        printf("Error:Matrix a's cols must be the same with b's rows.\n");
        return create_matrix(0, 0);
    }
    else
    {
        int i, j;
        for (i = 0; i < a.rows; i++)
        {
            for (j = 0; j < b.cols; j++)
            {
                c.data[i][j] = 0;
                int k = 0;
                while (k < b.rows)
                {
                    c.data[i][j] = c.data[i][j] + a.data[i][k] * b.data[k][j];
                    k++;
                }
            }
        }
        return c;
    }
    // ToDo finished
}

Matrix scale_matrix(Matrix a, double k)
{
    Matrix c = create_matrix(a.rows, a.cols);
    int i = 0, j = 0;
    for (i = 0; i < a.rows; i++)
    {
        for (j = 0; j < a.cols; j++)
        {
            c.data[i][j] = k * a.data[i][j];
        }
    }
    // ToDo finished
    return c;
}

Matrix transpose_matrix(Matrix a)
{
    Matrix c = create_matrix(a.cols, a.rows);
    int i, j = 0;
    for (i = 0; i < a.rows; i++)
    {
        for (j = 0; j < a.cols; j++)
        {
            c.data[j][i] = a.data[i][j];
        }
    }
    // ToDo finished
    return c;
}

double det_matrix(Matrix a)
{
    if (a.rows == a.cols)
    {
        double m = 0.0;
        int k = 1;
        if (a.cols > 2)
        {

            Matrix c = create_matrix(a.rows - 1, a.cols - 1);
            for (int l =0 ; l < a.cols; l++)
            {
                for (int i = 0; i < c.rows; i++)
                {
                    for (int j = 0; j < l; j++)
                    {
                        c.data[i][j] = a.data[i + 1][j];
                    }for(int j=l+1;j<a.cols;j++){
                        c.data[i][j-1]=a.data[i+1][j];
                    }
                }
                if(l%2==0)k=1;
                else k=-1;
                1;
                m=m+k*a.data[0][l]*det_matrix(c);
            }
            return m;
        }
        else if (a.cols == 2)
        {
            return a.data[0][0] * a.data[1][1] - a.data[0][1] * a.data[1][0];
        }
        else
        {
            return a.data[0][0];
        }
        // ToDo
    }
    else
    {
        printf("Matrix a's rows must be the same as its cols.\n");
        return 0;
    }
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
    if (a.rows != a.cols)
    {
        double k = 0.0;
        printf("Matrix a's rows must be the same as its cols.\n");
        return k;
    }
    else
    {
        double k = 0.0;
        int i = 0;
        for (i = 0; i < a.rows; i++)
        {
            k += a.data[i][i];
        }
        // ToDo finished
        return k;
    }
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