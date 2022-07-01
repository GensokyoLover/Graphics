#include <iostream>
#include <ifs.h>
#include <scene_parser.h>
#include <group.h>
#include <camera.h>
#include <fstream>
void assigment0(){
    std::cout << "Hello, World!" << std::endl;
    ifs newIfs = ifs("text1.txt");
    newIfs.Show();
    Image newImage(100,100);
    newIfs.Render(newImage,10000,10);
    newImage.SavePPM("ppm.ppm");
}



void assignment1(){
    struct node{
        string fileName;
        int width;
        int height;
        float miniDepth;
        float maxiDepth;
        string outPictureFileName;
        string outDepthPictureFileName;
    }no[10];
    ifstream configRead("input/assignment1/config.txt");
    if(configRead.is_open()) {
        for (int i = 0; i < 7; i++) {
            string waste;
            configRead >> no[i].fileName;
            no[i].fileName = "input/assignment1/" + no[i].fileName;
            configRead >> no[i].width;
            configRead >> no[i].height;
            configRead >> waste;
            configRead >> no[i].outPictureFileName;
            no[i].outPictureFileName = "input/assignment1/" + no[i].outPictureFileName;
            configRead >> waste;
            configRead >> no[i].miniDepth;
            configRead >> no[i].maxiDepth;
            configRead >> no[i].outDepthPictureFileName;
            no[i].outDepthPictureFileName = "input/assignment1/" + no[i].outDepthPictureFileName;
        }
    }
    else{
        cout<<"Config read error"<<endl;
        return ;
    }
    for(int i = 0; i < 7; i++) {
        const char *input_file = no[i].fileName.c_str();
        int width = no[i].width;
        int height = no[i].height;
        const char *output_file = no[i].outPictureFileName.c_str();
        float depth_min = no[i].miniDepth;
        float depth_max = no[i].maxiDepth;
        const char *depth_file = no[i].outDepthPictureFileName.c_str();
        SceneParser t1 = SceneParser(input_file);
        Group *iter = t1.getGroup();
        Image image(width, height);
        Image depthImage(width, height);
        for (int w = 0; w < width; w++) {
            for (int h = 0; h < height; h++) {
                float midW = w + 0.5;
                float midH = h + 0.5;
                Ray r = t1.getCamera()->generateRay(Vec2f(midW / width, midH / height));
                Hit hit = Hit(1e9, NULL);
                iter->intersect(r, hit, t1.getCamera()->getTMin());
                if (hit.getMaterial() != NULL) {
                    image.SetPixel(w, h, hit.getMaterial()->getDiffuseColor());
                    float depth = hit.getT();
                    depth = min(depth, depth_max);
                    depth = max(depth, depth_min);
                    Vec3f color = Vec3f(1, 1, 1) * (1 - (depth - depth_min) / (depth_max - depth_min));
                    depthImage.SetPixel(w, h, color);
                }
            }
        }
        image.SaveTGA(output_file);
        depthImage.SaveTGA(depth_file);
        cout << "ok: "<<i<<endl;
    }
}

int main(int argc, char *argv[]) {
    assignment1();
    return 0;
}