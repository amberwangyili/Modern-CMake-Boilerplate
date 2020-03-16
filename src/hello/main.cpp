#include <iostream>
#include <stdio.h>
#include <omp.h>
#include <string>




#include <boost/shared_ptr.hpp>

#include <hello/hello.h>

#include <GLFW/glfw3.h>
#include "private.h"
#include <opencv2/core.hpp>
#include <box2d/box2d.h>
using namespace std;


int omptest()
{
    int i;
    int threadID = 0;
    #pragma omp parallel for private(i, threadID)
    for(i = 0; i < 16; i++ )
    {
        threadID = omp_get_thread_num();
        #pragma omp critical
        {
            printf("Thread %d reporting\n", threadID);
        }
    }
    return 0;
}


int main(){
    hello();
    privatehello();
    std::cout << "Hello Third Party Include!" << std::endl;
    // use a shared ptr
    boost::shared_ptr<int> isp(new int(4));
    cout << "Built with OpenCV " << CV_VERSION << endl;
    omptest();
    
    return 0;
}