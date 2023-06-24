#include <map>
#include <algorithm>
class Kata
{
public:
    std::vector<int> sortArray(std::vector<int> array)
    {
      int i;
      int n = array.size();
      std::map<int, int> even;
      std::vector<int> odd;
      for(i=0; i<n; i++){
        if(array[i]%2 != 0){
          odd.push_back(array[i]);
        }else{
          even[i] = array[i];
        }
      }
      std::sort(odd.begin(), odd.end());
      int k = odd.size();
      i = 0;
      int j = 0;
      while(i<n){
        if(even.find(i) != even.end()){
          array[i] = even[i];
        }else{
          array[i] = odd[j];
          j ++;
        }
        i ++;
      }
      return array;
    }
};
