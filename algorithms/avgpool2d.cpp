#include <vector>
#include <climits>
#include <iostream>

class AvgPool2d{

    public:
        int step=2;


        AvgPool2d(int kernel){
            step = kernel;
        }

        std::vector<std::vector<std::vector<float>>> forward(std::vector<std::vector<std::vector<float>>> &x){
            std::vector<std::vector<std::vector<float>>> res;
            std::vector<std::vector<float>> temp1;
            std::vector<float> temp;
            float sum = 0;
            int i, j, k, l, m;
            for(i=0; i<x.size(); i++){
                for(j=0; j<x[i].size(); j+=step){
                    for(k=0; k<x[i][j].size(); k+=step){
                        for(l=0; l<step; l++){
                            for(m=0; m<step; m++){
                                sum += x[i][m+l][k+m];
                            }
                        }
                        temp.push_back((float)(sum/(step*step)));
                    }
                    temp1.push_back(temp);
                    std::vector<float>().swap(temp);
                }
                res.push_back(temp1);
                std::vector<std::vector<float>>().swap(temp1);
            }
            return res;
        }
};


int main(){
    std::vector<std::vector<std::vector<float>>> image;
    std::vector<std::vector<float>> temp1;
    std::vector<float> temp;
    std::vector<std::vector<std::vector<float>>> output;
    float r;
    int i, j, k;
    for(i=0; i<3; i++){
        for(j=0; j<32; j++){
            for(k=0; k<32; k++){
                r = ((float)rand()/RAND_MAX);
                temp.push_back(r);
            }
            temp1.push_back(temp);
            std::vector<float>().swap(temp);
        }
        image.push_back(temp1);
        std::vector<std::vector<float>>().swap(temp1);
    }

    AvgPool2d pool(2);
    output = pool.forward(image);
    std::cout << output.size() << " " << output[0].size() << " " << output[0][0].size() << "\n";
    return 0;
}
