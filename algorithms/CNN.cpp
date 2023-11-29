#include <iostream>
#include <climits>
#include <vector>

class Conv2d{
    public:
        Conv2d(int in_channels, int out_channels, int kernel_size, int stride, int padding){
            in_features = in_channels;
            out_features = out_channels;
            kernel = kernel_size;
            step = stride;
            pad = padding;
            int i, j, k, z;
            std::vector<float> temp1;
            std::vector<std::vector<float>> temp2;
            std::vector<std::vector<std::vector<float>>> temp3;
            float r;
            for(i=0; i<out_channels; i++){
                for(j=0; j<in_channels; j++){
                    for(k=0; k<kernel; k++){
                        for(z=0; z<kernel; z++){
                            r = ((float)rand()/RAND_MAX);
                            temp1.push_back(r);
                        }
                        temp2.push_back(temp1);
                        std::vector<float>().swap(temp1);
                    }
                    temp3.push_back(temp2);
                    std::vector<std::vector<float>>().swap(temp2);
                }
                filters.push_back(temp3);
                std::vector<std::vector<std::vector<float>>>().swap(temp3);
            }
        }

        std::vector<std::vector<std::vector<float>>> forward(std::vector<std::vector<std::vector<float>>> &x){
            int i, j, k, l, z, p;
            float res = 0.0f;
            std::vector<float> temp;
            for(i=0; i<in_features; i++){
                for(j=0; j<pad; j++){
                    temp.push_back(0.0f);
                }
                for(j=0; j<x[i][0].size(); j++){
                    temp.push_back(0.0f);
                }
                for(j=0; j<pad; j++){
                    temp.push_back(0.0f);
                }
                for(j=0; j<x[i].size(); j++){
                    for(k=0; k<pad; k++){
                        x[i][j].insert(x[i][j].begin()+0, 0.0f);
                        x[i][j].push_back(0.0f);
                    }
                }
                for(j=0; j<pad; j++){
                    x[i].insert(x[i].begin()+0, temp);
                    x[i].push_back(temp);
                }
            }
            std::vector<float> temp1;
            std::vector<std::vector<float>> temp2;
            std::vector<std::vector<std::vector<float>>> out;
            int count = 0;
            for(i=0; i<out_features; i++){
                for(k=0; k<=x[0].size()-kernel; k+=step){
                    for(l=0; l<=x[0][0].size()-kernel; l+=step){
                        for(j=0; j<in_features; j++){
                            for(z=0; z<kernel; z++){
                                for(p=0; p<kernel; p++){
                                    res += x[j][k+z][l+p]*filters[i][j][z][p];
                                }
                            }
                        }
                        temp1.push_back(res);
                        res = 0.0f;
                    }
                    temp2.push_back(temp1);
                    std::vector<float>().swap(temp1);
                }
                out.push_back(temp2);
                std::vector<std::vector<float>>().swap(temp2);
            }

            return out;
        }

    private:
        int in_features, out_features, kernel, step, pad;
        std::vector<std::vector<std::vector<std::vector<float>>>> filters;
};


int main(){
    std::vector<std::vector<std::vector<float>>> input;
    std::vector<std::vector<std::vector<float>>> output;
    std::vector<float> temp1;
    std::vector<std::vector<float>> temp2;
    int i, j, k;
    float r;
    for(i=0; i<3; i++){
        for(j=0; j<7; j++){
            for(k=0; k<7; k++){
                r = ((float)rand()/RAND_MAX);
                temp1.push_back(r);
            }
            temp2.push_back(temp1);
            std::vector<float>().swap(temp1);
        }
        input.push_back(temp2);
        std::vector<std::vector<float>>().swap(temp2);
    }
    Conv2d layer(3, 6, 3, 1, 0);
    output = layer.forward(input);
    for(i=0; i<6; i++){
        for(j=0; j<output[i].size(); j++){
            for(k=0; k<output[i][j].size(); k++){
                std::cout << output[i][j][k] << " ";
            }
            std::cout << "\n";
        }
        std::cout << "channel done\n";
    }
    std::cout << "{" << output.size() << ", " << output[0].size() << ", " << output[0][0].size() << "}\n";
    return 0;
}
