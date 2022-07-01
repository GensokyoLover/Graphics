//
// Created by gensokyolover on 2022/6/6.
//
#include"ifs.h"



void ifs::Show(){
    printf("Matrix_Cnt : %d\n",n);
    for(int i = 0; i < n; i++){
        printf("Matrix_No_%d's prob : %f\n",i,probVec[i]);
        for(int y = 0; y < 4; y++){
            for(int x = 0; x < 4; x++){
                printf("%f ",matrixVec[i].Get(x,y));
            }
            cout<<endl;
        }
    }
}

void ifs::Render(Image& img, int pointCnt, int iterCnt){
    int width = img.Width();
    int height = img.Height();
    for(int i=0;i<pointCnt;i++){
        Vec4f pos = Vec4f((float)(rand()%1000) / 1000  ,(float)(rand()%1000) / 1000 , 1, 1);
        for(int j = 0; j < iterCnt; j++) {
            float prob = (float)(rand()%1000) / 1000;
            int place = upper_bound(probPreSum.begin(), probPreSum.end(), prob) - probPreSum.begin()-1;
            matrixVec[place].Transform(pos);

        }
        int x = pos.x() * width,y=pos.y()*height;
        if(x<0 || x>=width||y<0||y>=height) continue;
        img.SetPixel(x, y, Vec3f(255,255,255));
    }
}