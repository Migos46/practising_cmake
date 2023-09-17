#include <iostream>

int main(int argc, char* argv[] ){
    if(argc < 2){
        std::cout << "Usage: " << argv[0] << " Number" << std::endl;
        return(0);
    }

    std::cout << "Hello world" << std::endl;
    return 0;
}