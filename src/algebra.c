/*
 * @Author: lyz 3068126392@qq.com
 * @Date: 2024-04-09 20:41:44
 * @LastEditors: lyz 3068126392@qq.com
 * @LastEditTime: 2024-04-26 09:24:50
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
        printf("Error: Matrix a's cols must be the same with b's rows.\n");
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
            for (int l = 0; l < a.cols; l++)
            {
                for (int i = 0; i < c.rows; i++)
                {
                    for (int j = 0; j < l; j++)
                    {
                        c.data[i][j] = a.data[i + 1][j];
                    }
                    for (int j = l + 1; j < a.cols; j++)
                    {
                        c.data[i][j - 1] = a.data[i + 1][j]; // 创建对应元素的余子式
                    }
                }
                if (l % 2 == 0)
                    k = 1;
                else
                    k = -1;
                m = m + k * a.data[0][l] * det_matrix(c);
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
        // ToDo finished
    }
    else
    {
        printf("Eorror: Matrix a's rows must be the same as its cols.\n");
        return 0.0;
    }
}

Matrix inv_matrix(Matrix a)
{
    if (a.rows == a.cols && det_matrix(a)!= 0)
    {
        Matrix c = create_matrix(a.rows - 1, a.cols - 1);
        Matrix d = create_matrix(a.rows, a.cols);
        Matrix e = create_matrix(a.rows, a.cols);
        int k = 1;
        int m, n = 0;
        for (n = 0; n < a.cols; n++)
        {
            for (m = 0; m < a.rows; m++)
            {
                for (int i = 0; i < m; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        c.data[i][j] = a.data[i][j];
                    }
                }
                for (int i = m + 1; i < a.rows; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        c.data[i - 1][j] = a.data[i][j];
                    }
                }
                for (int i = 0; i < m; i++)
                {
                    for (int j = n + 1; j < a.cols; j++)
                    {
                        c.data[i][j - 1] = a.data[i][j];
                    }
                }
                for (int i = m + 1; i < a.rows; i++)
                {
                    for (int j = n + 1; j < a.cols; j++)
                    {
                        c.data[i - 1][j - 1] = a.data[i][j];
                    }
                }
                
                int k = 0;
                k = m + n;
                if (k % 2 == 0)
                {
                    k = 1;
                    d.data[n][m] = det_matrix(c);
                }
                else
                {
                    k = -1;
                    d.data[n][m] = k * det_matrix(c);
                }
            }
        }
        double det = 0;
        det = det_matrix(a);
        e = scale_matrix(d, 1 / det);
        return e;
    }else{
        printf("Eorror: Matrix a's rows must be the same as its cols!\n");
        return create_matrix(0,0);
    }
    // ToDo finished
}

int rank_matrix(Matrix a)
{
    int rank,colsn=0,rowsn=0;
    if (a.rows <= a.cols)
        rank = a.rows;
    else
        rank = a.cols;
    
    for (int i = 0; i < a.cols-1; i++)
    {
        if (a.data[i][i] == 0)
        {
            int j = i + 1;
            while (a.data[j][i] == 0)
            {
                j = j + 1;
            } // 找非零
            if (j < a.rows){
            
                for (int k = 0; k < a.cols; k++)
                {
                    double m;
                    m = a.data[j][i];
                    a.data[j][k] = a.data[i][k];
                    a.data[i][k] = m;
                }  //在下面找到非零元素后，交换行
            for (int j = i + 1; j < a.rows; j++)
            {
                if (a.data[j][i] != 0)
                {   double solid=a.data[j][i];
                    for (int k = 0; k < a.cols; k++){
                        double result=solid*a.data[j][k]/a.data[i][i];
                        a.data[j][k] = a.data[j][k]-result;
                    }
                }
                else;//化成上三角形
            }
            }else;
        }
        else
        {
            for (int j = i+1; j < a.rows; j++)
            {
                if (a.data[j][i] != 0)
                {   double solid=a.data[j][i];
                    for (int k = 0; k < a.cols; k++){
                        double result=solid*a.data[i][k]/a.data[i][i];
                        a.data[j][k] = a.data[j][k]-result;
                    }
                }
                else;
            }
        }

    }for(int i=0;i<a.cols;i++){
       for(int j=0;j<a.rows;j++){
        if(a.data[j][i]!=0){
            colsn=colsn+1;
            break;
        }
       }
    }for(int i=0;i<a.rows;i++){
       for(int j=0;j<a.cols;j++){
        if(a.data[i][j]!=0){
            rowsn=rowsn+1;
            break;
        }
       }
    }
    int l=0;
    if(colsn>=rowsn)l=rowsn;
    else l=colsn;
    return l;  //ToDo finished
}

double trace_matrix(Matrix a)
{
    if (a.rows != a.cols)
    {
        printf("Eorror: Matrix a's rows must be the same as its cols.\n");
        return 0.0;
    }
    else
    {   
    double k=0.0;
    for(int i=0;i<a.rows;i++){
          k=k+a.data[i][i];
    }
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