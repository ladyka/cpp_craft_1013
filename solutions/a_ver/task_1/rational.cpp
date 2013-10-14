#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

#define ACCURACY 10000

int main(){
    vector<int> passwd;
    ifstream i_fs(SOURCE_DIR "/Input.txt");
    ofstream o_fs(SOURCE_DIR "/Output.txt");
    int count;
    double value;
    if(!i_fs){
        cout << "Could not open input file" << endl;
        return 1;
    }
    if(!o_fs){
        cout << "Could not open output file" << endl;
        return 1;
    }

    i_fs >> count;

    passwd.reserve(count);
    for(int i=0; i < count && !i_fs.eof(); i++){
        i_fs >> value;
        passwd.push_back(value*ACCURACY);
    }
    sort(passwd.begin(), passwd.end());
    
    i_fs >> value;
    while(!i_fs.eof()){
        if(binary_search(passwd.begin(), passwd.end(),
           (int) (value*ACCURACY))){
            o_fs << "YES" << endl;
        }else{
            o_fs << "NO" << endl;
        }
        i_fs >> value;
    }
    o_fs.close();
    i_fs.close();
    return 0;
}
