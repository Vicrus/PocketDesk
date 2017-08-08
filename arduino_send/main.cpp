#include <iostream>
#include <fstream>

using namespace std;
int main() {

    int x = 0;
    int y = 0;
    int id = 0;
    ofstream arduino;

    //ofstream arduino(path, ifstream::binary);

    while (true) {
        string path;
        path = "/dev/ttyACM" + to_string(id);
        cout<<path<<endl;
        arduino.open(path, ofstream::binary);
        if(arduino.is_open()) {
            break;
        }
        else if (id <=4){
            arduino.close();
            id++;
        } else{
            arduino.close();
            cout<<"error to find serial port"<<endl;
            break;
        }
    }

    arduino<<10<<" "<<200<<" "<<15<<" "<<"0xFF25"<<endl;
    arduino.close();
    return 0;
}