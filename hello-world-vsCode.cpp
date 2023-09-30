#include <iostream>

int main(int argc, char* argv[] ){
    if(argc < 2){
#ifdef USE_LOG
        std::cout << "Usage: " << argv[0] << " Number" << std::endl;
#endif
        return(0);
    }
#ifdef USE_LOG
    std::cout << "Hello world: Your number is " << argv[1] << std::endl;
#endif
    return 0;
}