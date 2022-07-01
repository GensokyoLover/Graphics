//
// Created by gensokyolover on 2022/6/6.
//

#ifndef GRAPHICS_IFS_H
#define GRAPHICS_IFS_H

#include<vector>
#include<set>
#include<stdio.h>
#include<iostream>
#include<fstream>

#include"image.h"
#include"matrix.h"
#include"vectors.h"

using namespace std;

class ifs{
private:
    int n;
    vector<float> probVec;
    vector<float> probPreSum;
    vector<Matrix> matrixVec;

public:
    ifs(string filePath){
        ifstream in(filePath);
        if(in.is_open())
            printf("yes");
        in >> n;
        printf("%d\n",n);
        float nowProbability = 0;
        probPreSum.push_back(0);
        for(int i = 0; i < n; i++){
            float f;
            in >> f;
            nowProbability += f;
            probPreSum.push_back(nowProbability);
            probVec.push_back(f);
            float matrixData[16];
            memset(matrixData,0,sizeof(matrixData));
            for(int y = 0; y < 4; y++){
                if(y == 2){
                    continue;
                }
                for(int x = 0; x < 4 ; x++){
                    if(x == 2) continue;
                    in >> matrixData[y * 4 + x];
                }
            }
            matrixVec.push_back(Matrix(matrixData));
        }
        in.close();
    }
    void Show();
    void Render(Image& img, int pointCnt, int iterCnt);
};

#endif //GRAPHICS_IFS_H
